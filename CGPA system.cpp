#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;

int main() 
{
    stack<double> percentage;
    queue<string> grade;
    double gpa;
    int n, s;
    cout << "Enter number of Students" << endl;
    cin >> n;
    cout << "Enter number of Subjects" << endl;
    cin >> s;
 double CGP[n];
    int a[n][s];
    double GPA=0.0;
    double GP[n];
    // Input marks for each student and subject
    for (int i = 0; i < n; i++)
	 {
        cout << "---Enter marks of Student " << i + 1 << endl;
        for (int j = 0; j < s; j++) 
		{
            cout << "Enter marks of subject " << j + 1 << endl;
            cin >> a[i][j];
        }
    }
    double gpa1 = 0.0, gpa2 = 0.0;
    cout << "-------------------------------------" << endl;
    cout << "Enter attendance of each subject" << endl;
    int att[s];

    // Take attendance
    double attendance = 0.0;
    for (int i = 0; i < s; i++)
	 {
        cout << "Enter attendance of subject " << i + 1 << endl;
        cin >> att[i];
        attendance = attendance + att[i];
    }
    cout << "------------------------------------------" << endl;
    // Total marks
    int total;
    cout << "Enter total marks of subject" << endl;
    cin >> total;
    int a1 = 0;
    cout << "Enter previous number of semesters" << endl;
    cin >> a1;
    double cgpa[n][a1];  // Use a 2D array to store GPAs for each student and each semester
    string r;
    double gpa3;
    int passcount=0;
    int failcount=0;
    cout << "| Student | Subject | Marks | Total | Percentage   | Grade  | GPA     |" << "Result|" << endl;
    // Calculate percentages and push them onto the stack
       for (int i = 0; i < n; i++)
	 {
	 	gpa2=0.0;
	 bool h= false;
        for (int j = 0; j < s; j++)
		 {
            double per = (a[i][j] * 100.0) / total;
            percentage.push(per);
            // Calculate and enqueue GPA based on the percentage
            string g;
            float gpa;
            if (per >= 85)
			 {
                g = "A+";
                r = "pass";
                gpa = 4.0;
                gpa1 = 4.0 * att[j];
            }
              else if (per >= 80)
            {
                g = "A";
                r="pass";
                gpa=3.7;
                gpa1=3.7*att[j];
            }
                else if (per >= 75)
            {
                g = "B+";
               
                r="pass";
                gpa=3.3;
                gpa1=3.3*att[j];
            }
            else if (per >= 70)
            {
                g = "B";
                 
	            r="pass";
                gpa=3.0;
                gpa1=3.0*att[j];
            }
            else if (per >= 65)
            {
                g = "B-";
                
                r="pass";
                gpa=2.7;
                gpa1=2.7*att[j];
            }
            else if (per >= 60)
            {
                g = "C+";  
                r="pass";
                gpa=2.3;
                gpa1=2.3*att[j];
            }
            else if (per >= 55)
            {
                g = "C";
               
                r="pass";
                gpa=2.0;
                gpa1=2.0*att[j];
            }
            else if (per >= 51)
            {
                g = "C-";
                
                r="pass";
                gpa=1.7;
                gpa1=1.7*att[j];
            }
            else if (per == 50)
            {
                g = "D";
              
                r="pass";
                gpa=1.0;
                gpa1=1.0*att[j];
            }
            else
            {
                g = "F";
                r="fail";
                gpa=0.0;
                gpa1=0.0;
                h= true;
            }
            grade.push(g);
            cout<<"|  "<<i+1<<"      |  "<<j+1<<"      |"<<a[i][j]<<"     |"<<total<<"    |"<<"  "<< fixed << setprecision(1) << setw(5)<<percentage.top()<<"%      |"<<g<<"       | "<< fixed << setprecision(1) << setw(5)<<gpa<<"   |"<<r<<"  |"<<endl;
         gpa2=gpa2+gpa1;
        }
        cout << "------------------------------------------------------------------------------------" << endl;
    
        if(h)
        {
        GPA = gpa2 / attendance;
        cout << "GPA is " << GPA << endl;
        cout<<"Fail"<<endl;
        failcount++;
       }
       else
       {
       	GPA = gpa2 / attendance;
        cout << "GPA is " << GPA << endl;
        cout<<"Pass"<<endl;
        passcount++;
	   }
	   GP[i]=GPA;
        gpa3 = GPA;
        GPA = 0.0;
        // Collect GPA information for each semester
        for (int j = 1; j <= a1; j++) {
            cout << "Enter GPA of semester " << j << " for Student " << i + 1 << endl;
            cin >> cgpa[i][j];
            gpa3 = gpa3 + cgpa[i][j];
        }
        // Calculate CGPA
        double CGPA = gpa3 / (a1 + 1);
        cout << "CGPA is " << CGPA << endl;
        CGP[i]=CGPA;
        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
  cout<<"| Number of Pass students in semester "<<a1+1 <<" is "<<passcount<<" |"<<endl;
  cout<<"| Number of Fail students in semester "<<a1+1 <<" is "<<failcount<<" |"<<endl;
  cout<<"-----------------------------------------------------------------------------------------------"<<endl;
  cout<<"----------------------------OR-------------------------------------------------------"<<endl;
  cout<<" Student | ";
  for(int i=1; i<=s;i++)
  {
  	cout<<"Subject"<<i<<"  | ";
  }
  cout<<"Obtain | Total | Percentage | Grade | GPA  | CGPA"<<endl;
  int ad=0;
  for(int i=0; i<n;i++)
  {
  	ad=0;
  	cout<<"  "<<i+1<<"      |";
  	for(int j=0; j< s; j++)
  	{
  	      cout<<a[i][j]<<"         |";
  	      ad=ad+a[i][j];
	  }
	  cout<<ad<<"    |  "<< total*s <<"   |"<<(ad*100)/(total*s)<<"%         |";
	 int h=(ad*100)/(total*s);
	 if(h>=85)
	 {
    cout<<"A+    |";
    }
	 else if(h>=80)
	 {
	 cout<<"A      |";
     }
	else if(h>=75)
	{
	 cout<<"B+     |";
    }
	else if(h>=70)
	{
	 cout<<"B      |";
    }
	 else if(h>=65)
	{ 
	 cout<<"B-     |";
    }
	 else if(h>=60)
	 {
	 cout<<"C+     |";
     }
	 else if(h>=55)
	 {
	 
	 cout<<"C      |";
    }
	 else if(h>=51)
	 {
	 cout<<"C-     |";
     }
	 else if(h==50)
	 {
	 cout<<"D      |";
    }
	 else
	 { 
	 cout<<"F      |";
      }
      cout<<GP[i]<<"   |"<<CGP[i];
	  cout<<endl;
}
	return 0;
}
