namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public class Complex1 // ��������� �����
        {
            public double a; // �������������� ����� �.�.
            public double b; // ������ ����� �.�
            public double A;
            public double KSI;


            public Complex1(double x1, double x2) // �����������
            {
                a = x1;
                b = x2;
            }

        }

        public void Polar() // ��������� ����� Polar
        {
            double x1 = Convert.ToDouble(textBox1.Text);
            double x2 = Convert.ToDouble(textBox2.Text);

            Complex1 complex = new Complex1(x1, x2);



            complex.A = Math.Sqrt(Math.Pow(complex.a, 2) + Math.Pow(complex.b, 2));
            textBox3.Text = complex.A.ToString();

            complex.KSI = (Math.Atan(complex.b / complex.a) * 180) / Math.PI;
            textBox4.Text = complex.KSI.ToString();
        }


        private void button1_Click(object sender, EventArgs e)
        {

            Polar();// ��������� ������ �.�. � ������� ������ Polar
        }
    }
}