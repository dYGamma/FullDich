import matplotlib.pyplot as plt

l = 0.5  # м
d = 0.7 / 1000  # м
t1 = 20  # градусов Цельсия
t2 = 80  # градусов Цельсия
ρ0 = 4.89 * 10**-8  # Ом * м
α = 5.1 * 10**-3  # 1/градус Цельсия
Δt = 6  # градусов Цельсия
R1 = 0.0158  # Ω
R2 = 0.0206  # Ω

# Функция для расчета сопротивления R в зависимости от температуры t
def calculate_resistance(t):
    R = R1 * (1 + α * (t - t1))  # Расчет сопротивления по формуле R = R1 * (1 + α * (t - t1))
    return R

# Создание списков значений температуры и сопротивления для построения графика
temperatures = list(range(t1, t2 + Δt, Δt))
resistances = [calculate_resistance(t) for t in temperatures]

# Построение графика
plt.plot(temperatures, resistances, marker='o')
plt.title('График зависимости сопротивления проводника от температуры')
plt.xlabel('Температура, градусы Цельсия')
plt.ylabel('Сопротивление, Ом')
plt.grid()
plt.show()