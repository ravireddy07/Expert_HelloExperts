// Phonebook project
//===============================

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;


//prototypes
void printline(char, int);
bool name_valid(string);
bool mob_valid(string);


class contact
{
    string name;
    string mob;
        
    public:
    	//Initialize the contact by a default value
        contact(): name(""), mob("")
        {}
        
        // Shows all contacts
        bool show()
        {
            if(name != "")
            {
                cout << name << "\t" << mob << endl;
                return 1; //Indicates success
            }
            else
                return 0; //Indicates failure
        }
        
        //Search
        bool show(string search_term)
        {
            if(search_term == name)
            {
                cout << name << "\t" << mob << endl;
                return 1;
            }
            else
                return 0;
        }
        
        //Checks whether the name exists or not
        bool name_exists(string tname)
        {
            if(tname == name)
                return 1;
            else
                return 0;
        }
        
        //The contact object is initialized by valid values
        bool add(string new_name, string new_mob)
        {
            if(name=="")
            {
                name = new_name;
                mob = new_mob;
                return 1; // Success
            }
            else
                return 0; // Failure
    
        }
        
        //Edits the contact details
        bool edit(string);
        
        //Sets the contact details to default values
        //That is, the contact details are thus erased
        bool erase(string new_name)
        {
            if(new_name==name)
            {       
                name = "";
                mob = "";
                return 1;
            }
            else
                return 0;
        }
};


//Edits the contact
bool contact :: edit(string new_name)
{
    string new_mob;
    if(new_name==name)
    {
        cout << "Enter new name: "; cin >> new_name;
        cout << "Enter new mobile no: "; cin >> new_mob;
        
        name = new_name;
        mob = new_mob;
        return 1;
    }
    else
        return 0;
}



int main()
{
    contact person[100];
            
    string temp_name, temp_mob;
    int choice, i, counter;
    bool flag;
    bool cancel_flag;
    
    cout << "HELLO...YOU ARE IN PHONEBOOK" << endl;
    
    
    do
    {  system("color 4E "); 
        cout << "\n\n\n";
        printline('-', 20);
        cout << "0. Show contacts" << endl
        << "1. Add Contact" << endl
        << "2. Edit Contact" << endl
        << "3. Delete Contact" << endl
        << "4. Search" << endl
        << "5. Quit" << endl << endl
        << "Your choice...  ";
        cin >> choice;
        
        system("cls");
        printline('-', 20);
        cancel_flag = 0;
        flag = 0;
        counter = 0;
        
        switch(choice)
        {
            case 0: 
                cout << "Showing Contacts" << endl;
                printline('-', 20);
                
                for(i=0; i<100; i++)
                    if(person[i].show())
                        flag = 1;
                
                if(!flag)
                    cout << "No contacts found!" << endl;
                break;
                
            case 1:
                cout << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
                printline('-', 20);
                counter = 0;
                
                //Loop until correct name and mobile number are entered
                do
                {
                    flag = 0;
                    if(counter)
                        cout << "Try again\t\t\t\tpress $ to cancel" 
						<< endl;
						
                    //counts how many times the do-while loop executes
					counter++; 
                        
                    cout << "Name: "; cin >> temp_name;
                    
                    //Cancel operation
                    if(temp_name=="$")
                    {
                        cancel_flag = 1;
                        break;
                    }
                    cout << "Mobile No.: "; cin >> temp_mob;
                    
                    //Cancel operation
                    if(temp_mob=="$")
                    {
                        cancel_flag = 1;
                        break;
                    }
                    
                    //Check whether name exists
                    for(i=0; i<100; i++)
                        if(person[i].name_exists(temp_name))
                        {
                            cout << "The name you entered is already there" 
							"in the phonebook, enter a different name." 
							<< endl;
                            flag = 1;
                            break;
                        }
                    
                }while(!name_valid(temp_name) || 
								flag ||
						!mob_valid(temp_mob));
                
                if(cancel_flag)
                {
                    system("cls");
                    break;
                }
            
                
                //This code adds the contact to phonebook    
                for(i=0; i<100; i++)
                    if(person[i].add(temp_name, temp_mob))
                    {
                        cout << "Contact added successfully!" << endl;
                        flag = 1;
                        break;
                    }
                
                if(!flag)
                    cout << "Memory full! Delete some contacts first." 
					<< endl;
                break;
                
            case 2:
                cout << "Enter a contact name to edit:" 
				"\t\t\t\tpress $ to cancel\n";
				 cin >> temp_name;
                
                //Cancel Operation
                if(temp_name=="$")
                {
                    system("cls");
                    break;
                }
                
                for(i=0; i<100; i++)
                    if(person[i].edit(temp_name))
                    {
                        cout << "Edited Successfully!" << endl;
                        flag = 1;
                        break;
                    }
                
                if(!flag)
                    cout << "Contact name not found!" << endl;
                break;
                
            case 3:
                do
                {
                    if(counter)
                        cout << "Try again" << endl;
                    counter++;
                    cout << "Enter a contact name to delete:" 
					"\t\t\tpress $ to cancel\n"; 
					cin >> temp_name;
                
                    //Cancel Operation
                    if(temp_name=="$")
                    {
                        system("cls");
                        break;
                    }
                
                
                    //Final Confirmation
                    for(i=0; i<100; i++)
                    if(person[i].name_exists(temp_name))
                    {
                        flag = 1;
                        cout << "Are you sure you want to delete? (1/0)" 
						<< endl;
                        int yes;
                        cin >> yes;
                        if(!yes)
                        {
                            system("cls");
                            cancel_flag = 1;
                        }
                        break;
                    }
                
                    if(!flag)
                        cout << "Contact name not found!" << endl;
                    
                    if(cancel_flag)
                        break;
                
                    // This code deletes the contact
                    if(flag)
                    {
                        for(i=0; i<100; i++)
                            if(person[i].erase(temp_name))
                            {
                                cout << "Deleted successfully!" << endl;
                                break;
                            }
                    }
                    
                }while(!flag);
                break;
                
            case 4:
                do
                {
                    if(counter)
                        cout << "Try again" << endl;
                    counter++;
                    cout << "Search a name: \t\t\t\tpress $ to cancel\n";
					 cin >> temp_name;
                
                    //Cancel Operation
                    if(temp_name=="$")
                    {
                        system("cls");
                        break;
                    }
                
                    for(i=0; i<100; i++)
                        if(person[i].show(temp_name))
                        {
                            flag = 1;
                            break;
                        }
    
                    if(!flag)
                        cout << "Contact name not found" << endl;
                }while(!flag);
                    
                break;
                
            case 5:
                return 0;
                break;
            
        }
    } while(1);
    
    getch();
    return 0;
}

//prints a line
void printline(char ch, int size)
{
    for(int i=0; i<size; i++)
        cout << ch;
    cout << "\n";
}


//Contact name validation
bool name_valid(string tname)
{
    
    if(tname.size()>20)
    {
        cout << "Invalid Name!\nEnter a name within 20 characters!" 
		<< endl;
        return 0;
    }
    else if(tname == "")
    {
        cout << "Invalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

//mobile number validation
bool mob_valid(string tmob)
{
    if(tmob.size()>13 || tmob.size()<10)
    {
        cout << "Invalid mobile no.\nEnter a no." 
		"between 10 and 13 digits" << endl;
        return 0;
    }
    else if(tmob == "")
    {
        cout << "Invalid mobile no.\nMobile" 
		"no cannot be blank" << endl;
        return 0;
    }
    else
        return 1;
}
