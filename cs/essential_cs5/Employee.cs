using System;

class Employee
{
    public string FirstName
    {
        get
        {
            return _FirstName;
        }
        set
        {
            if (value == null)
            {
                throw new ArgumentNullException("value");
            }
            else
            {
                value = value.Trim();
                if (value == "")
                {
                    throw new ArgumentException(
                            "FirstName cannot be blank.", "value");
                }
                else
                    _FirstName = value;
            }
        }
    }
    private string _FirstName;

    public string LastName
    {
        get
        {
            return _LastName;
        }
        set
        {
            if (value == null)
            {
                throw new ArgumentNullException("value");
            }
            else
            {
                value = value.Trim();
                if (value == "")
                {
                    throw new ArgumentException(
                            "LastName cannot be black.", "value");
                }
                else
                    _LastName = value;
            }
        }
    }
    private string _LastName;

    public string Title { get; set; }

    public Employee Manager { get; set; }
}
