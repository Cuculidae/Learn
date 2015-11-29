using System;
using System.IO;

class DataStorage
{
    /* Save an Employee Object to a file named with the Employee name.
     * Error handling no shown.
     */
    public static void Store(Employee employee)
    {
        FileStream stream = new FileStream(
                employee.FirstName + employee.LastName + ".dat",
                FileMode.Create);
        StreamWriter writer = new StreamWriter(stream);
        writer.WriteLine(employee.FirstName);
        writer.WriteLine(employee.LastName);
        writer.WriteLine(employee.Salary);
        // close the StreamWriter and its Stream
        writer.Close();
    }

    public static Employee Load(string firstName, string lastName)
    {
        Employee employee = new Employee();
        FileStream stream = new FileStream(
                firstName + lastName + ".dat", FileMode.Open);
        StreamReader reader = new StreamReader(stream);
        employee.FirstName = reader.ReadLine();
        employee.LastName = reader.ReadLine();
        employee.Salary = reader.ReadLine();
        // close the StreamReader and its Stream
        reader.Close();
        return employee;
    }
}
