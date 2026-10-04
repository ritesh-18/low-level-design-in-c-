// how to open a file and read it using c++
#include <iostream>
#include <fstream>
using namespace std;
void writeToFile(string filename, string content)
{
    try
    {
        /* code */
        // create an object of ofstream class to write to a file
        ofstream outfile(filename);
        if (!outfile.is_open())
        {
            throw runtime_error("Error opening file");
        }
        // write the content to the file
        outfile << content;
        // close the file
        outfile.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

//append to a file


    void appendToFile(string filename, string content)
    {
        try
        {
            // create an object of ofstream class to write to a file
            ofstream outfile(filename, ios::app);
            if (!outfile.is_open())
            {
                throw runtime_error("Error opening file");
            }
            // write the content to the file
            outfile << content;
            // close the file
            outfile.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    int main()
    {

        string filename="dummy.txt";
        string content="This is a dummy file created for testing file handling in C++.";
        writeToFile(filename, content);

        //append to the file
        string appendContent="\nThis is an appended content.";
        appendToFile(filename, appendContent);



        // create an object of ifstream class to read from a file
        ifstream inputFile("dummy.txt");
        // check if the file is open
        if (!inputFile.is_open())
        {
            cout << "Error opening file" << endl;
        }
        // read the contents of the file and print it to the console
        cout << "Contents of the file are: " << endl;
        for (string line; getline(inputFile, line);)
        {
            cout << line << endl;
        }
        cout << "File read successfully!" << endl;
        // close the file
        inputFile.close();
        return 0;
    }