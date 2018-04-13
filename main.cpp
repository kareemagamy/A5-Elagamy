/*************************************************************************
* Name: Karim Elagamy                                                    *
* Program: CSC 175 Assignment 5                                          *
* Due Date: 4/13/2018                                                    *
* Program function: This program is for a magazine company to handle     *
* their subscription list. This program will allow the user to enter the *
* details for every subscriber including: First Name, Last Name, Street  *
* Address, City, State or Province, Country, Zip Code or Postal Code,    *
* Expiration date of their subscription, and their subscriber number.    *
* This program will store this info in a file called INPUT.txt and then  *
* sort active subscribers into a file called REPORT.txt and then expired *
* or inactive subscribers into a file called EXPIRED.txt. This program   *
* will also check for invalid expiry dates and any customers with an     *
* invalid expiry date will be written to a file called INVALID.txt       *
**************************************************************************/
#include<iostream>

#include<string>

#include<vector>

#include<fstream>

using namespace std;

ofstream INPUT;
ofstream EXPIRED;
ofstream INVALID;
ofstream REPORT;

class Subscriber{

public :

int subscriberNumber;

string lastName;

string firstName;

string streetAddress;

string city;

string state;

string country;

int zipcode;

int expirationdate;

};

class SubscriberHandling{

private :

int sub_id;

int curDate;

vector<Subscriber> subscribers;

public:

SubscriberHandling(int date);

void hardCode();

void addSubscriber();

void expiredSubscriptions();

void unexpiredSubscriptions();

void subscriptionsInState(string state);

void subscriptionExpiringInTwoMonths();

void searchSubscriber(int num);

};

//driver function

int main()

{

cout<<"Enter the current date:"<<endl;

int date;

cin>>date;

int num;

string s;

int choice=-1;

//make new subscriber handling object with current date set

SubscriberHandling sh(date);

do{

switch(choice)

{

case 1:sh.addSubscriber();break;//call add subscriber method

case 2:

cout<<"\nEnter the id"<<endl;

cin>>num;

sh.searchSubscriber(num);//call the search subscriber method

break;

case 3:

cout<<"\nEnter the state name:"<<endl;

cin>>s;

sh.subscriptionsInState(s);

break;//call subscriptions in state method

case 4:sh.unexpiredSubscriptions();break;//call unexpired subscriptions method

case 5:sh.expiredSubscriptions();break;//call expired subscriptions method

case 6:sh.subscriptionExpiringInTwoMonths();break;//call subscriptionExpiringInTwoMonths method

}

cout<<"\n-------------------ENTER CHOICE--------------------"<<endl<<endl;

cout<<"1.Enter a new subscriber:"<<endl;

cout<<"2.Search for an existing subscriber by Subscriber Number:"<<endl;

cout<<"3.Display all subscriptions in a particular state:"<<endl;

cout<<"4.Display all unexpired subscriptions:"<<endl;

cout<<"5.Display all expired subscriptions:"<<endl;

cout<<"6.Display all subscriptions expiring in two months:"<<endl;

cout<<"7.Exit"<<endl<<endl;

cin>>choice;

}while(choice!=7);

cout<<"\n\nTerminating the program....."<<endl<<endl;

cin.get();//to hold the console screen

cin.get();//to hold the console screen

return 0;

}

//parameter constructor

SubscriberHandling::SubscriberHandling(int date){

curDate=date;//set current date

sub_id=101;//initial value of subscriber

hardCode();

}

//hardcode method

void SubscriberHandling:: hardCode()

{

Subscriber one;

one.subscriberNumber=sub_id;

sub_id++;

one.lastName="Gray";

one.firstName="John";

one.streetAddress="233 Parkview Road";

one.city="Flushing";

one.state="Michigan";

one.zipcode=47489;

one.expirationdate=1809;

Subscriber two;

two.subscriberNumber=sub_id;

sub_id++;

two.lastName="Tang";

two.firstName="Charlotte";

two.streetAddress="303 E. Kearsley Street";

two.city,"Flint";

two.state,"Michigan";

two.zipcode=48502;

two.expirationdate=1712;

Subscriber three;

three.subscriberNumber=sub_id;

sub_id++;

three.lastName="Brown";

three.firstName="Coral";

three.streetAddress="8890 Holly Road";

three.city="Grand Blanc";

three.state="Michigan";

three.zipcode=48439;

three.expirationdate=1709;

Subscriber four;

four.subscriberNumber=sub_id;

sub_id++;

four.lastName="Arai";

four.firstName="Hugh";

four.streetAddress="77 Riverside Walk";

four.city="San Antonio";

four.state="Texas";

four.zipcode=25786;

four.expirationdate=1805;

Subscriber five;

five.subscriberNumber=sub_id;

sub_id++;

five.lastName="Blackett";

five.firstName="Kevin";

five.streetAddress="125 Picking Circle";

five.city="San Jose";

five.state="California";

five.zipcode=60089;

five.expirationdate=1704;

Subscriber six;

six.subscriberNumber=sub_id;

sub_id++;

six.lastName="Achtemichuk";

six.firstName="Mark";

six.streetAddress="3987 143 St";

six.city="Flint";

six.state="Michigan";

six.zipcode=48503;

six.expirationdate=1810;

Subscriber seven;

seven.subscriberNumber=sub_id;

sub_id++;

seven.lastName="Browning";

seven.firstName="William";

seven.streetAddress="1 Down Street";

seven.city="Washington";

seven.state="D.C.";

seven.zipcode=24675;

seven.expirationdate=1712;



Subscriber eight;

eight.subscriberNumber=sub_id;

sub_id++;

eight.lastName="Brown";

eight.firstName="Maureen";

eight.streetAddress="9066 Osoyoo Crescent";

eight.city="New York City";

eight.state="New York";

eight.zipcode=10021;

eight.expirationdate=180;



//add the subscribers into the list

subscribers.push_back(one);

subscribers.push_back(two);

subscribers.push_back(three);

subscribers.push_back(four);

subscribers.push_back(five);

subscribers.push_back(six);

subscribers.push_back(seven);

subscribers.push_back(eight);

}

//add subscriber function

void SubscriberHandling::addSubscriber()

{

//create a new subscriber

string s;

Subscriber sub;

sub.subscriberNumber=sub_id;//set the subscriber id

sub_id++;//increment the sub id

cout<<"Enter the details of the subscriber:\n"<<endl;

cout<<"Enter The first name: "<<endl;

getline(cin,s);

getline(cin,s);//a second time to bypass the enter pressed

sub.firstName=s;

cout<<"Enter The last name:"<<endl;

getline(cin,s);

sub.lastName=s;

cout<<"Enter The STREET ADDRESS:"<<endl;

getline(cin,s);

sub.streetAddress=s;

cout<<"Enter The CITY:"<<endl;

getline(cin,s);

sub.city=s;

cout<<"Enter The STATE:"<<endl;

getline(cin,s);

sub.state=s;

cout<<"Enter the COUNTRY:"<<endl;

getline(cin,s);

sub.country=s;

cout<<"Enter The ZIP CODE or POSTAL CODE:"<<endl;

cin>>sub.zipcode;

cout<<"Enter The EXPIRATION DATE:"<<endl;

cin>>sub.expirationdate;//input first name of subscriber

subscribers.push_back(sub);//add the subscriber to the list

}

//expired subscriptions

void SubscriberHandling::expiredSubscriptions()

{



vector<Subscriber> :: iterator ite;//get an iterator of subscriber type

cout<<"\nThe expired subscriptions are: "<<endl;

//from begin to end of list

for(ite=subscribers.begin();ite!=subscribers.end();ite++)

{

if((*ite).expirationdate<=curDate)

{//found the subscriber

//print the info



cout<<"\nfirst name: "<<(*ite).firstName<<endl;

cout<<"last name: "<<(*ite).lastName<<endl;

cout<<"street Address: "<<(*ite).streetAddress<<endl;

cout<<"city: "<<(*ite).city<<endl;

cout<<"state: "<<(*ite).state<<endl;

cout<<"country: "<<(*ite).country<<endl;

cout<<"zip code or postal code: "<<(*ite).zipcode<<endl;

cout<<"expiration date: "<<(*ite).expirationdate<<endl<<endl;



}

}

}

//subscriptions expiring in 2 months

void SubscriberHandling::subscriptionExpiringInTwoMonths()

{

vector<Subscriber> :: iterator ite;//get an iterator of subscriber type

cout<<"\nThe subscriptions expiring in 2 months are: "<<endl;

//from begin to end of list

for(ite=subscribers.begin();ite!=subscribers.end();ite++)

{

if((*ite).expirationdate-curDate<=2)

{//found the subscriber

//print the info



cout<<"\nfirst name: "<<(*ite).firstName<<endl;

cout<<"last name: "<<(*ite).lastName<<endl;

cout<<"street Address: "<<(*ite).streetAddress<<endl;

cout<<"city: "<<(*ite).city<<endl;

cout<<"state: "<<(*ite).state<<endl;

cout<<"country: "<<(*ite).country<<endl;

cout<<"zip code or postal code: "<<(*ite).zipcode<<endl;

cout<<"expiration date: "<<(*ite).expirationdate<<endl<<endl;

}

}

}

//search for a subscriber using id

void SubscriberHandling::searchSubscriber(int num)

{

vector<Subscriber> :: iterator ite;//get an iterator of subscriber type

//from begin to end of list

for(ite=subscribers.begin();ite!=subscribers.end();ite++)

{

if((*ite).subscriberNumber==num)

{//found the subscriber

//print the info

cout<<"\nThe Subscriber with ID: "<<num<<" has information as follows:\n"<<endl;

cout<<"first name: "<<(*ite).firstName<<endl;

cout<<"last name: "<<(*ite).lastName<<endl;

cout<<"street Address: "<<(*ite).streetAddress<<endl;

cout<<"city: "<<(*ite).city<<endl;

cout<<"state: "<<(*ite).state<<endl;

cout<<"country: "<<(*ite).country<<endl;

cout<<"zip code or postal code: "<<(*ite).zipcode<<endl;

cout<<"expiration date: "<<(*ite).expirationdate<<endl;

return;//return from the function

}

}

cout<<"No such subscriber with this ID exists"<<endl;//else there is not subscriber with id

}

//subscriptions in a state

void SubscriberHandling::subscriptionsInState(string state)

{

vector<Subscriber> :: iterator ite;//get an iterator of subscriber type

cout<<"\nThe subscribers in state: "<<state<<" are:\n"<<endl;

//from begin to end of list

for(ite=subscribers.begin();ite!=subscribers.end();ite++)

{

if((*ite).state==state)

{//found the subscriber

//print the info

//cout<<"The Subscriber with id "<<num<<" has information as follows :"<<endl;

cout<<"\nfirst name: "<<(*ite).firstName<<endl;

cout<<"last name: "<<(*ite).lastName<<endl;

cout<<"street Address: "<<(*ite).streetAddress<<endl;

cout<<"city: "<<(*ite).city<<endl;

cout<<"state: "<<(*ite).state<<endl;

cout<<"country: "<<(*ite).country<<endl;

cout<<"zip code or postal code: "<<(*ite).zipcode<<endl;

cout<<"expiration date: "<<(*ite).expirationdate<<endl<<endl;

}

}

}

//display subscriptions unexpired

void SubscriberHandling::unexpiredSubscriptions()

{

vector<Subscriber> :: iterator ite;//get an iterator of subscriber type

cout<<"\nThe Unexpired subscriptions are :"<<endl;

//from begin to end of list

for(ite=subscribers.begin();ite!=subscribers.end();ite++)

{

if((*ite).expirationdate>curDate)

{//found the subscriber

//print the info



cout<<"\nfirst name: "<<(*ite).firstName<<endl;

cout<<"last name: "<<(*ite).lastName<<endl;

cout<<"street Address: "<<(*ite).streetAddress<<endl;

cout<<"city: "<<(*ite).city<<endl;

cout<<"state: "<<(*ite).state<<endl;

cout<<"country: "<<(*ite).country<<endl;

cout<<"zip code or postal code: "<<(*ite).zipcode<<endl;

cout<<"expiration date: "<<(*ite).expirationdate<<endl<<endl;

}

}

}
