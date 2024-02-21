
class Angle
{
    double VALUE;
    bool isGrad = true;

    public bool IsGrad
    {
        get { return isGrad; }
        set { isGrad = value; }
    }

        public double Gradus
        {
            get { return VALUE; }
            set
            {
                if (value > 360)
                    VALUE = value - 360;
                else VALUE = value;
            }
        }

            public double RadToGrad()
            {
                if (isGrad == true)
                {
                    Console.WriteLine("Ќевозможно перевести в градусы");
                    return 0;
                }
                else
                {
                    isGrad = true;
                    return VALUE * 180 / 3.14;
                }

            }

            public double GradToRad()
            {
                if (isGrad == true)
                {
                    isGrad = false;
                    return VALUE * 3.14 / 180;
                }
                else
                {
                    Console.WriteLine("Ќевозможно перевести в радианны");
                    return 0;
                }
            }

            public static double operator +(Angle obj1, Angle obj2)
            {
                double Result = 0;
                if (obj1.isGrad == true && obj2.isGrad == true)
                {
                    if ((obj1.Gradus + obj2.Gradus) > 360)
                    {
                        Result = Math.Abs(360 - (obj1.Gradus + obj2.Gradus));
                    }
                    else Result = obj1.Gradus + obj2.Gradus;
                }
                else
                {
                    Console.WriteLine("ƒл€ сложени€ углов, дл€ начала переведите их в градусы");
                }

                return Result;
            }

            public static double operator -(Angle obj1, Angle obj2)
            {
                double Result = 0;
                if (obj1.isGrad == true && obj2.isGrad == true)
                {
                    if ((obj1.Gradus - obj2.Gradus) < 0)
                    {
                        Result = 360 - Math.Abs((obj1.Gradus - obj2.Gradus));
                    }
                    else Result = obj1.Gradus - obj2.Gradus;
                }
                else
                {
                    Console.WriteLine("ƒл€ вычитани€ углов, дл€ начала переведите их в градусы");
                }

                return Result;
            }
}

