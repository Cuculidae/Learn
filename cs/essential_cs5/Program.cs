using System;

class Program
{
    static void Main()
    {
        Employee employee1 = new Employee();
        Employee employee2 = new Employee();

        employee1.FirstName = "Inigo";
        Console.WriteLine(employee1.FirstName);

        employee2.Title = "Computer Nerd";
        employee1.Manager = employee2;

        Console.WriteLine(employee1.Manager.Title);
    }

}
