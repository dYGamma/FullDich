#include <functional>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>
#include <regex>

// заранее объявляется функция поиска в тексте, чтобы использовать ее до ее реализации

int32_t bm_search(const std::string&, const std::string&);

// базовые структуры для работы

struct guest {
    std::string passport_info;
    std::string full_name;
    uint16_t yob;
    std::string address;
    std::string purpose_of_visit;

    void display() {
        std::cout << "Паспорт: " << passport_info << "\n";
        std::cout << "Полное имя: " << full_name << "\n";
        std::cout << "Год рождения: " << yob << "\n";
        std::cout << "Адрес: " << address << "\n";
        std::cout << "Цель визита: " << purpose_of_visit << "\n\n";
    }
};

struct room {
    std::string room_code;
    size_t capacity;
    size_t n_rooms;
    bool has_restroom;
    std::string equipment;

    void display() {
        std::cout << "Номер: " << room_code << "\n";
        std::cout << "Вместимость: " << capacity << "\n";
        std::cout << "Число комнат: " << n_rooms << "\n";
        std::cout << "Наличие уборной: " << (has_restroom ? "да" : "нет") << "\n";
        std::cout << "Оборудование: " << equipment << "\n\n";
    }
};

struct log_record {
    std::string room_code;
    std::string passport_info;
    std::string date_in;
    std::string date_out;

    void display() {
        std::cout << "Номер: " << room_code << "\n";
        std::cout << "Паспорт: " << passport_info << "\n";
        std::cout << "Дата заселения: " << date_in << "\n";
        std::cout << "Дата выселения: " << date_out << "\n\n";
    }
};

// структуры данных

// хэш-таблица
// вариант хэширования - закрытое с квадратичным опробованием
// для квадратичного опробывания удобно, чтобы размер таблицы был степенью двойки

struct hash_node {
    bool taken = false;
    std::string key;
    guest value;
};

struct hash_table {
    size_t size;
    std::vector<hash_node> data{};

    // конструктор
    hash_table(size_t power_of_two) {
        size = std::pow(2, power_of_two);
        data.resize(size);
    }

    // опробывание
    size_t get_index(size_t hash, size_t iter_num) {
        return (hash + (iter_num + iter_num * iter_num) / 2) % size;
    }

    // получение элемента по ключу
    guest& get(const std::string& key) {
        size_t iter_num = 1;
        size_t hash = std::hash<std::string>{}(key);
        while (iter_num <= size) {
            size_t index = get_index(hash, iter_num);
            auto& node = data[index];
            if (node.taken && node.key == key)
                return node.value;
            iter_num++;
        }
        std::cout << "element not found in hashtable\n";
        std::exit(1);
    }

    // Проверка, содержится ли в таблице элемент с данным ключом
    bool contains(const std::string& key) {
        size_t iter_num = 1;
        size_t hash = std::hash<std::string>{}(key);
        while (iter_num <= size) {
            size_t index = get_index(hash, iter_num);
            auto& node = data[index];
            if (node.taken && node.key == key)
                return true;
            iter_num++;
        }
        return false;
    }

    // Удаление элемента из таблицы
    void remove(const std::string& key) {
        size_t iter_num = 1;
        size_t hash = std::hash<std::string>{}(key);
        while (iter_num <= size) {
            size_t index = get_index(hash, iter_num);
            auto& node = data[index];
            if (node.taken && node.key == key)
                node.taken = false;
            iter_num++;
        }
    }

    // Присваивание по ключу либо добавление пары в таблицу
    void set(const std::string& key, guest value) {
        size_t iter_num = 1;
        size_t hash = std::hash<std::string>{}(key);

        while (iter_num <= size) {
            size_t index = get_index(hash, iter_num);
            auto& node = data[index];

            if (node.taken && node.key == key) {
                node.value = value;
                return;
            }
            if (!node.taken) {
                node.taken = true;
                node.key = key;
                node.value = value;
                return;
            }
            iter_num++;
        }
        std::cout << "element not found in hashtable and the hashtable is full\n";
        std::exit(1);
    }

    // быстрый вывод всех полей
    void display() {
        for (auto item : data) {
            if (item.taken) {
                std::cout << "Паспорт: " << item.value.passport_info
                    << "\nФИО: " << item.value.full_name << "\nГод рождения: " << item.value.yob << "\n\n";
            }
        }
    }

    // поиск по именам указанным по варианту алгоритмом (реализован ниже)
    void search_by_name(const std::string& name) {
        for (auto item : data) {
            if (item.taken && bm_search(item.value.full_name, name) >= 0) {
                std::cout << "Паспорт: " << item.value.passport_info
                    << "\nФИО: " << item.value.full_name << "\nГод рождения: " << item.value.yob << "\n\n";
            }
        }
    }
};

// односвязный циклический список

// определим операторы сравнения для структуры записи журнала
inline bool operator< (const log_record& lhs, const log_record& rhs) { return lhs.room_code < rhs.room_code; }
inline bool operator> (const log_record& lhs, const log_record& rhs) { return rhs < lhs; }
inline bool operator<=(const log_record& lhs, const log_record& rhs) { return !(lhs > rhs); }
inline bool operator>=(const log_record& lhs, const log_record& rhs) { return !(lhs < rhs); }

struct list_node {
    std::shared_ptr<list_node> next;
    log_record data;
};

struct l_list {
    std::shared_ptr<list_node> head;
    size_t size = 0;

    // получение записи по индексу
    log_record& get(size_t index) {
        size_t i = 0;
        auto node = head;
        while (i < index) {
            node = node->next;
            i++;
        }
        return node->data;
    };

    // удаление элемента по индексу с возвратом значение
    log_record pop(size_t index) {
        size_t i = 0;

        auto node = head;
        auto prev_node = node;

        while (i < index) {
            node = node->next;
            i++;
        }

        while (prev_node->next != node)
            prev_node = prev_node->next;

        prev_node->next = node->next;

        size--;

        if (node == head) {
            if (size == 0) {
                head = nullptr;
            }
            else {
                head = head->next;
            }
        }

        return node->data;
    }

    // добавление элемента
    void push_front(log_record data) {
        if (!head) {
            head = std::make_shared<list_node>(list_node{ {}, data });
            head->next = head;
            size++;
            return;
        }
        auto node = head;
        do { node = node->next; } while (node->next != head);
        node->next = std::make_shared<list_node>(list_node{ node->next, data });
        size++;
    };

    // быстрый вывод
    void display() {
        if (!head)
            return;

        auto node = head;
        do {
            std::cout << "[ " <<
                node->data.room_code << " " <<
                node->data.passport_info << " ]\n";
            node = node->next;
        } while (node != head);
        std::cout << std::endl;

    }

    // сортировка распределением. осуществляется не in-place,
    // отсортированный список - возвращаемое значение
    l_list sorted() {
        if (size < 2)
            return *this;

        std::vector<log_record> auxilary{};

        auxilary.resize(1001);

        for (size_t i = 0; i < size; i++) {
            const auto& rc = get(i).room_code;
            size_t room_index = std::stoi(rc.substr(2, 3));
            auxilary[room_index] = get(i);
        }

        l_list rv;
        for (auto l_r : auxilary) {
            if (l_r.room_code.size() == 5) {
                rv.push_front(l_r);
            }
        }
        return rv;

    }

    // подсчет числа постояльцев в комнате
    size_t guests_currently_in_room(const std::string& room_code) {
        size_t rv = 0;
        for (size_t i = 0; i < size; i++) {
            auto rec = get(i);
            if (rec.room_code == room_code && rec.date_out == "") rv++;
        }
        return rv;
    }

    // проверка, в комнате ли сейчас гость
    bool is_guest_in_room(const std::string& room_code, const std::string& passport_info) {
        for (size_t i = 0; i < size; i++) {
            auto rec = get(i);
            if (rec.room_code == room_code && rec.passport_info == passport_info && rec.date_out == "") return true;
        }
        return false;
    }

    // выселение постояльца
    void move_out(const std::string& room_code, const std::string& passport_info, const std::string& date_out) {
        for (size_t i = 0; i < size; i++) {
            auto& rec = get(i);
            if (rec.room_code == room_code && rec.passport_info == passport_info && rec.date_out == "") rec.date_out = date_out;
        }
    }
};


// avl-дерево

// аналогично добавляем нашей структуре операторы сравнения
inline bool operator< (const room& lhs, const room& rhs) { return lhs.room_code < rhs.room_code; }
inline bool operator> (const room& lhs, const room& rhs) { return rhs < lhs; }
inline bool operator<=(const room& lhs, const room& rhs) { return !(lhs > rhs); }
inline bool operator>=(const room& lhs, const room& rhs) { return !(lhs < rhs); }

// тут немного мешанина, некоторые алгоритмы реализованы как
// методы структуры узла, некоторые - как просто функции

struct tree_node {
    std::shared_ptr<tree_node> left;
    std::shared_ptr<tree_node> right;

    room data;

    // вывод всех элементов в возрастающем порядке
    void display_subtree() {
        if (left) left->display_subtree();
        data.display();
        if (right) right->display_subtree();

    }

    // вывод всех комнат, в описании которых нашлась строка из поискового запроса
    void filter_by_equipment(const std::string& query) {
        if (left) left->filter_by_equipment(query);
        if (bm_search(data.equipment, query) >= 0) data.display();
        if (right) right->filter_by_equipment(query);
    }

    // подсчет баланс-фактора
    long get_balance_factor() {
        long hl = 0, hr = 0;
        if (right)
            hr = right->get_height();

        if (left)
            hl = left->get_height();

        return hl - hr;
    }

    // подсчет высоты дерева
    size_t get_height() {
        if (!left && !right)
            return 1;

        if (!left)
            return right->get_height() + 1;

        if (!right)
            return left->get_height() + 1;

        auto left_height = left->get_height();
        auto right_height = right->get_height();
        return (left_height > right_height ? left_height : right_height) + 1;
    }

};


// поворот направо
auto rotate_right(std::shared_ptr<tree_node> base) {
    auto left_tree = base->left;
    base->left = left_tree->right;
    left_tree->right = base;
    return left_tree;
}

// поворот налево
auto rotate_left(std::shared_ptr<tree_node> base) {
    auto right_tree = base->right;
    base->right = right_tree->left;
    right_tree->left = base;
    return right_tree;
}

// рекурсивная вставка
auto insert_into_subtree(std::shared_ptr<tree_node> base, room data) {
    if (!base)
        return std::make_shared<tree_node>(tree_node{ {}, {}, data });

    bool b_insert_left = data < base->data;

    if (b_insert_left)
        base->left = insert_into_subtree(base->left, data);
    else
        base->right = insert_into_subtree(base->right, data);

    auto bf = base->get_balance_factor();

    if (bf == 2 && data < base->left->data)
        return rotate_right(base);
    if (bf == -2 && data > base->right->data)
        return rotate_left(base);
    if (bf == 2 && data > base->left->data) {
        base->left = rotate_left(base->left);
        return rotate_right(base);
    }
    if (bf == -2 && data < base->right->data) {
        base->right = rotate_right(base->right);
        return rotate_left(base);
    }

    return base;

}

// нахождение узла с наименьшим значением, нужно для удаления
auto min_val_node(std::shared_ptr<tree_node> base) {
    auto node = base;
    while (node->left) node = node->left;
    return node;
}

// рекурсивное удаление
auto delete_from_subtree(std::shared_ptr<tree_node>& base, const std::string& room_code) {
    if (!base)
        return base;

    if (room{ room_code } < base->data)
        base->left = delete_from_subtree(base->left, room_code);
    else if (room{ room_code } > base->data)
        base->right = delete_from_subtree(base->right, room_code);

    else {
        if (!(base->left && base->right)) {
            auto& the_only_child = base->left ? base->left : base->right;
            if (!the_only_child) {
                base.reset();
            }
            else {
                base->data = the_only_child->data;
                the_only_child.reset();
            }
        }
        else {
            auto successor = min_val_node(base->right);
            base->data = successor->data;
            base->right = delete_from_subtree(base->right, successor->data.room_code);
        }
    }

    if (!base)
        return base;

    auto bf = base->get_balance_factor();

    if (bf == 2 && base->left->get_balance_factor() >= 0)
        return rotate_right(base);

    if (bf == 2 && base->left->get_balance_factor() < 0) {
        base->left = rotate_left(base->left);
        return rotate_right(base);
    }

    if (bf == -2 && base->right->get_balance_factor() <= 0)
        return rotate_left(base);

    if (bf == -2 && base->right->get_balance_factor() > 0) {
        base->right = rotate_right(base->right);
        return rotate_left(base);
    }

    return base;

}

// проверка на присуствие в поддереве
bool present_in_subtree(std::shared_ptr<tree_node> base, const std::string& room_code) {
    if (!base) {
        return false;
    }

    if (base->data.room_code == room_code) {
        return true;
    }

    if (base->data > room{ room_code }) {
        return present_in_subtree(base->left, room_code);
    }

    return present_in_subtree(base->right, room_code);
}

// поиск в поддереве
room& find_in_subtree(std::shared_ptr<tree_node> base, const std::string& room_code) {
    if (!base) {
        std::cout << "Item not found in tree\n";
        std::exit(1);
    }

    if (base->data.room_code == room_code) {
        return base->data;
    }

    if (base->data > room{ room_code }) {
        return find_in_subtree(base->left, room_code);
    }

    return find_in_subtree(base->right, room_code);
}

// в основной структуре дерева в основном вызовы алгоритмов для головной вершины

struct avl_tree {
    std::shared_ptr<tree_node> head;

    void insert(room value) {
        head = insert_into_subtree(head, value);
    }

    void display() {
        if (!head)
            return;
        head->display_subtree();
    }

    room& find(const std::string& room_code) {
        return find_in_subtree(head, room_code);
    }

    bool present(const std::string& room_code) {
        return present_in_subtree(head, room_code);
    }

    void remove(const std::string& room_code) {
        head = delete_from_subtree(head, room_code);
    }

    void filter_by_equipment(const std::string& query) {
        if (head) head->filter_by_equipment(query);
    }
};

// поиск строки методом Бауера-Мура

bool is_prefix(const std::string& needle, size_t p) {
    size_t j = 0;
    for (size_t i = p; i < needle.size(); i++) {
        if (needle[i] != needle[j]) {
            return false;
        }
        j++;
    }
    return true;
}

size_t suffix_length(const std::string& needle, size_t p) {
    size_t len = 0;
    size_t j = needle.size() - 1;
    for (int i = p; i >= 0 && needle[i] == needle[j]; i--) {
        len += 1;
        j--;
    }
    return len;
}

int32_t bm_search(const std::string& haystack, const std::string& needle) {
    size_t abc_size = std::numeric_limits<unsigned char>::max() + 1;
    std::vector<size_t> char_table{};

    char_table.resize(abc_size, needle.size());

    for (size_t i = 0; i < needle.size(); i++) {
        char_table[(unsigned char)needle[i]] = needle.size() - 1 - i;
    }

    std::vector<size_t> offset_table{};
    offset_table.resize(needle.size());

    size_t last_pref_pos = needle.size();
    for (size_t i = needle.size(); i > 0; i--) {
        if (is_prefix(needle, i)) {
            last_pref_pos = i;
        }
        offset_table[needle.size() - i] = last_pref_pos - i + needle.size();
    }

    for (size_t i = 0; i < needle.size() - 1; i++) {
        size_t suf_len = suffix_length(needle, i);
        offset_table[suf_len] = needle.size() - 1 - i + suf_len;
    }
    size_t j;
    for (size_t i = needle.size() - 1; i < haystack.size();) {
        for (j = needle.size() - 1; needle[j] == haystack[i]; j--) {
            if (j == 0) {
                return (int32_t)i;
            }
            i--;
        }
        i += offset_table[needle.size() - 1 - j] > char_table[(unsigned char)haystack[i]] ? offset_table[needle.size() - 1 - j] : char_table[(unsigned char)haystack[i]];
    }
    return -1;

}

// там используются и операторы >> << и std::getline, из-за чего в некоторых ситуациях необходимо очищать буфер std::cin
// чтобы очистка была более читаема, она обернута в эту функцию

void flush_buffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
    // 4096 посетителей нам должно хватить
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
    const size_t hash_table_size_log2 = 12;

    // наши структуры данных

    hash_table guests(hash_table_size_log2);
    l_list logs;
    avl_tree rooms;

    // регулярные выражения для проверки ввода
    std::regex passport_info_regex{ "\\d{4}-\\d{6}" };
    std::regex room_code_regex{ "(Л|П|О|М)\\d{3}" };
    std::regex yob_regex{ "(19|20)\\d{2}" };
    std::regex single_digit_regex{ "\\d" };
    std::regex yesno_regex{ "(да|нет)" };

    std::string prompt;

    std::string welcome_message = "Добро пожаловать в панель управления отелем Гранд Будапешт. Для получения списка команд введите 'помощь'\n";

    std::cout << welcome_message;

    // из цикла можно выйти, набрав "выход", ну или просто нажав Ctrl+C в консоли.

    while (true) {

        std::cout << "\nВведите команду: ";
        std::getline(std::cin, prompt);

        // проверяется, начинается ли ввод пользователя
        // так же, как команда, поэтому местами можно не дописывать команду целиком

        // далее незатейливым образом обрабатываются все доступные команды

        if (prompt.rfind("выход", 0) == 0)
            break;

        if (prompt.rfind("помощь", 0) == 0) {
            std::cout << "\n Введите команду 'помощь', для вывода команд. \n 0 - Добавить нового постояльца \n 2 - Удалить постояльца \n 3 - Вывод постояльцев отеля \n 4 - Очистить постояльцев \n 5 - Поиск постояльца по паспорту \n 6 - Поиск постояльца по ФИО \n 7 - Добавить новый номер \n 8 - Вывод номеров отеля \n 9 - Поиск информации о номере \n 10 - Удалить номер \n 11 - Очистить номера \n 12 - Поиск номера по оборудованию \n 13 - Заселить постояльца \n 14 - Выселить постояльца \n Для выхода, введите: выход\n";
            continue;
        }

        if (prompt.rfind("0", 0) == 0) {
            std::string passport_info_prompt;
            std::string full_name;
            std::string yob_prompt;
            uint16_t yob;
            std::string address;
            std::string purpose;

            do {
                std::cout << "Введите паспортные данные: \n";
                std::cin >> passport_info_prompt;
            } while (!std::regex_match(passport_info_prompt, passport_info_regex));

            flush_buffer();

            std::cout << "Введите полное имя: \n";
            std::getline(std::cin, full_name);

            do {
                std::cout << "Введите год рождения: \n";
                std::cin >> yob_prompt;
            } while (!regex_match(yob_prompt, yob_regex));
            yob = std::stoi(yob_prompt);

            flush_buffer();

            std::cout << "Введите адрес: \n";
            std::getline(std::cin, address);

            std::cout << "Введите цель визита: \n";
            std::getline(std::cin, purpose);

            guests.set(passport_info_prompt, {
                passport_info_prompt,
                full_name,
                yob,
                address,
                purpose
                });
            continue;
        }

        if (prompt.rfind("2", 0) == 0) {
            std::string passport_info_prompt;
            do {
                std::cout << "Введите паспортные данные: \n";
                std::cin >> passport_info_prompt;
            } while (!std::regex_match(passport_info_prompt, passport_info_regex));

            flush_buffer();

            if (guests.contains(passport_info_prompt)) {
                guests.remove(passport_info_prompt);
                for (size_t i = 0; i < logs.size; i++) {
                    if (logs.get(i).passport_info == passport_info_prompt) {
                        logs.pop(i);
                    }
                }
                std::cout << "Постоялец успешно удален\n";
            }
            else {
                std::cout << "Постояльца с таким номер паспорта не найдено\n";
            }
            continue;
        }

        if (prompt.rfind("3", 0) == 0) {
            std::cout << "В случае отсутсвия какой-либо информации, добавьте нового гостя через консольное меню. \nПолученная информация о постояльцах:\n";
            guests.display();
            //std::cout << "\nПостояльцы отсутствуют? Самое время добавить нового гостя!";
            continue;
        }

        if (prompt.rfind("4", 0) == 0) {
            guests = hash_table{ hash_table_size_log2 };
            logs = l_list{};
            std::cout << "Постояльцы успешно удалены\n";
            continue;
        }

        if (prompt.rfind("5", 0) == 0) {
            std::string passport_info_prompt;
            do {
                std::cout << "Введите паспортные данные: \n";
                std::cin >> passport_info_prompt;
            } while (!std::regex_match(passport_info_prompt, passport_info_regex));
            flush_buffer();

            if (guests.contains(passport_info_prompt)) {
                guests.get(passport_info_prompt).display();
                for (size_t i = 0; i < logs.size; i++) {
                    if (logs.get(i).passport_info == passport_info_prompt && logs.get(i).date_out == "") {
                        logs.get(i).display();
                        break;
                    }
                }
            }
            else {
                std::cout << "Постоялец с таким номером паспорта не найден\n";
            }
            continue;
        }

        if (prompt.rfind("6", 0) == 0) {
            std::string full_name_prompt;

            std::cout << "Введите запрос: ";
            std::cin >> full_name_prompt;
            flush_buffer();
            std::cout << "В случае отсутсвия какой-либо информации, добавьте нового гостя через консольное меню. \nПолученная информация:\n";

            guests.search_by_name(full_name_prompt);
            continue;
        }

        if (prompt.rfind("7", 0) == 0) {
            std::string room_code_prompt;
            std::string capacity_prompt;
            size_t capacity;
            std::string num_rooms_prompt;
            size_t num_rooms;
            std::string restroom_prompt;
            bool has_restroom;
            std::string equipment;

            do {
                std::cout << "Введите номер: \n";
                std::cin >> room_code_prompt;
            } while (!std::regex_match(room_code_prompt, room_code_regex));

            do {
                std::cout << "Введите вместимость: \n";
                std::cin >> capacity_prompt;
            } while (!std::regex_match(capacity_prompt, single_digit_regex));

            capacity = std::stoi(capacity_prompt);

            do {
                std::cout << "Введите число комнат: \n";
                std::cin >> num_rooms_prompt;
            } while (!std::regex_match(num_rooms_prompt, single_digit_regex));

            num_rooms = std::stoi(num_rooms_prompt);

            do {
                std::cout << "Укажите наличие туалета (да/нет): \n";
                std::cin >> restroom_prompt;
            } while (!std::regex_match(restroom_prompt, yesno_regex));

            has_restroom = restroom_prompt == "да";

            flush_buffer();

            std::cout << "Укажите оборудование: \n";
            std::getline(std::cin, equipment);

            rooms.insert({
                room_code_prompt,
                capacity,
                num_rooms,
                has_restroom,
                equipment
                });

            continue;
        }

        if (prompt.rfind("8", 0) == 0) {
            std::cout << "В случае отсутсвия какой-либо информации, добавьте новый номер отеля через консольное меню. \nПолученная информация:\n";

            rooms.display();
            continue;
        }

        if (prompt.rfind("9", 0) == 0) {
            std::string room_code_prompt;

            do {
                std::cout << "Введите номер: \n";
                std::cin >> room_code_prompt;
                flush_buffer();
            } while (!std::regex_match(room_code_prompt, room_code_regex));

            if (rooms.present(room_code_prompt)) {
                rooms.find(room_code_prompt).display();

                for (size_t i = 0; i < logs.size; i++) {
                    if (logs.get(i).room_code == room_code_prompt && logs.get(i).date_out == "") {
                        logs.get(i).display();
                    }
                }

                std::cout << "Занято мест: " << logs.guests_currently_in_room(room_code_prompt) << "\n";
            }
            else {
                std::cout << "Номер не найден\n";
            }

            continue;
        }

        if (prompt.rfind("10", 0) == 0) {
            std::string room_code_prompt;

            do {
                std::cout << "Введите номер: \n";
                std::cin >> room_code_prompt;
                flush_buffer();
            } while (!std::regex_match(room_code_prompt, room_code_regex));

            if (rooms.present(room_code_prompt)) {
                rooms.remove(room_code_prompt);
                for (size_t i = 0; i < logs.size; i++) {
                    if (logs.get(i).room_code == room_code_prompt) {
                        logs.pop(i);
                    }
                }
                std::cout << "Номер успешно удален\n";
            }
            else {
                std::cout << "Номер не найден\n";
            }

            continue;
        }

        if (prompt.rfind("11", 0) == 0) {
            rooms = avl_tree{};
            logs = l_list{};
            std::cout << "Номера успешно удалены\n";
            continue;
        }

        if (prompt.rfind("12", 0) == 0) {
            std::string equipment_prompt;

            std::cout << "Введите запрос: ";
            std::cin >> equipment_prompt;
            flush_buffer();

            rooms.filter_by_equipment(equipment_prompt);
            continue;
        }

        if (prompt.rfind("13", 0) == 0) {
            std::string room_code_prompt;
            std::string passport_info_prompt;
            std::string date_in;

            do {
                std::cout << "Введите номер: \n";
                std::cin >> room_code_prompt;

            } while (!std::regex_match(room_code_prompt, room_code_regex));

            if (!rooms.present(room_code_prompt)) {
                std::cout << "Номер не найден\n";
                flush_buffer();
                continue;
            }

            auto r = rooms.find(room_code_prompt);

            if (logs.guests_currently_in_room(room_code_prompt) >= r.capacity) {
                std::cout << "Номер заполнен\n";
                flush_buffer();
                continue;
            }

            do {
                std::cout << "Введите паспортные данные: \n";
                std::cin >> passport_info_prompt;
            } while (!std::regex_match(passport_info_prompt, passport_info_regex));
            flush_buffer();

            if (!guests.contains(passport_info_prompt)) {
                std::cout << "Постоялец с таким номером паспорта не найден\n";
                continue;
            }

            auto g = guests.get(passport_info_prompt);

            std::cout << "Введите дату въезда: \n";
            std::getline(std::cin, date_in);

            logs.push_front({ r.room_code, g.passport_info, date_in });

            continue;
        }

        if (prompt.rfind("14", 0) == 0) {
            std::string room_code_prompt;
            std::string passport_info_prompt;
            std::string date_out;

            do {
                std::cout << "Введите номер: \n";
                std::cin >> room_code_prompt;

            } while (!std::regex_match(room_code_prompt, room_code_regex));

            if (!rooms.present(room_code_prompt)) {
                std::cout << "Номер не найден\n";
                flush_buffer();
                continue;
            }

            auto r = rooms.find(room_code_prompt);

            if (logs.guests_currently_in_room(room_code_prompt) == 0) {
                std::cout << "Номер пуст\n";
                flush_buffer();
                continue;
            }

            for (size_t i = 0; i < logs.size; i++) {
                if (logs.get(i).room_code == room_code_prompt && logs.get(i).date_out == "") {
                    logs.get(i).display();
                    break;
                }
            }

            do {
                std::cout << "Введите паспортные данные: \n";
                std::cin >> passport_info_prompt;
            } while (!std::regex_match(passport_info_prompt, passport_info_regex));
            flush_buffer();

            if (!guests.contains(passport_info_prompt)) {
                std::cout << "Постоялец с таким номером паспорта не найден\n";
                continue;
            }

            if (!logs.is_guest_in_room(room_code_prompt, passport_info_prompt)) {
                std::cout << "Постоялец с таким номером паспорта не проживает в этом номере\n";
                continue;
            }

            std::cout << "Введите дату выезда: \n";
            std::getline(std::cin, date_out);

            logs.move_out(room_code_prompt, passport_info_prompt, date_out);

            continue;
        }

        std::cout << "Команда не распознана\n";
    }

    return 0;
}
