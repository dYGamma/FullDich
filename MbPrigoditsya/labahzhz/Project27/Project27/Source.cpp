#include <iostream> 


void count_pos(int(&A)[4][7], double& countpos, double& countn, double& avg)
{
    countpos = 0;
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 7; j++)
        {
            if (A[i][j] >= 0)
            {
                countpos++;
            }

        }

    }

    countn = 0;
    for (int i = 0; i < 4; i++) {



        for (int j = 0; j < 7; j++)
        {
            if (A[i][j] == 0)
            {
                countn++;
            }

        }

    }


    int count = 0;
    int sum = 0;
    for (int i = 0; i < 4; i++) {


        for (int j = 0; j < 7; j++)
        {
            if (A[i][j] < 0)
            {
                sum = sum + A[i][j];
                count++;
            }

        }

    }
    avg = 0;
    if (count)
    {
        avg = sum / count;
    }


}


int main()
{
    int x[4][7];
    int y[4][7];

    std::cout << "Enter array x: ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cin >> x[i][j];
        }
    }

    std::cout << "Enter array y: ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cin >> y[i][j];
        }
    }
    std::cout << "array x: \n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << x[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "array y: \n"; 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << y[i][j] << "\t";
        }
        std::cout << "\n";
    }


    double xavg, xnul, xpos;
    double yavg, ynul, ypos;
    count_pos(x, xpos, xnul, xavg);
    count_pos(y, ypos, ynul, yavg);

    std::cout << "Num of positive in x: " << xpos << '\n';
    std::cout << "Num of positive in y: " << ypos << '\n';

    std::cout << "average of neg x: " << xavg << "\n";
    std::cout << "average of neg y: " << yavg << "\n";

    std::cout << "count of null x: " << xnul << "\n";
    std::cout << "count of null y: " << ynul << "\n";





}
