#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct flightSample
{	
	char airline[50];
	char flightnumber[50];
	char destination[50];
	char departureTime[50];
	char arrivaltime[50];
	char gate[10];
	char status[50];
	char aircraftType[50];
	int  seatsAvailable;
	int  economySeats;
	int  businessSeats;
	struct flightSample *next;
}*flight=NULL;

struct flightDetails {
    char airline[3][50];  
    char flightnumber[3][50];
    char destination[3][50];
    char departureTime[3][50];
    char arrivaltime[3][50];
    char gate[3][50];
    char status[3][50];
    char aircraftType[3][50];
    int seatsAvailable[3];
    int economySeats[3];
    int businessSeats[3];
} details = {
    {"Air India", "IndiGo", "SpiceJet"},
    {"AI202", "6E409", "SG123"},
    {"Mumbai", "Bangalore", "Kolkata"},
    {"7:30 AM", "9:00 AM", "10:45 AM"},
    {"9:10 AM", "11:00 AM", "12:55 PM"},
    {"A2", "B6", "C4"},
    {"On Time", "Delayed", "On Time"},
    {"Airbus A320", "Boeing 737", "Airbus A321"},
    {45, 20, 30},
    {40, 17, 21},
    {5, 3, 9}
};

void createFlight() 
{	
	int i;
	struct flightSample *t,*last;
	flight=(struct flightSample*)malloc(sizeof(struct flightSample));
	strcpy(flight->airline, details.airline[0]);
    strcpy(flight->flightnumber, details.flightnumber[0]);
    strcpy(flight->destination, details.destination[0]);
    strcpy(flight->departureTime, details.departureTime[0]);
    strcpy(flight->arrivaltime, details.arrivaltime[0]);
    strcpy(flight->gate, details.gate[0]);
    strcpy(flight->status, details.status[0]);
    strcpy(flight->aircraftType, details.aircraftType[0]);
    flight->seatsAvailable= details.seatsAvailable[0];
    flight->economySeats= details.economySeats[0];
    flight->businessSeats= details.businessSeats[0];
    flight->next=NULL;
    last=flight;
    for(i=1;i<3;i++)
    {	
    	t=(struct flightSample*)malloc(sizeof(struct flightSample));
    	strcpy(t->airline, details.airline[i]);
    	strcpy(t->flightnumber, details.flightnumber[i]);
    	strcpy(t->destination, details.destination[i]);
    	strcpy(t->departureTime, details.departureTime[i]);
    	strcpy(t->arrivaltime, details.arrivaltime[i]);
    	strcpy(t->gate, details.gate[i]);
    	strcpy(t->status, details.status[i]);
    	strcpy(t->aircraftType, details.aircraftType[i]);
    	t->seatsAvailable= details.seatsAvailable[i];
    	t->economySeats= details.economySeats[i];
    	t->businessSeats= details.businessSeats[i];
    	t->next=NULL;
    	last->next=t;
    	last=t;
	}
}
struct bookingDetails
{
	char name[50];
	char contactDetails[10];
	int age;
	int passengerType;
	char flightNumber[20];
	char seatType[20];
	int numberOfSeats;
	int paymentStatus;//0=pending,1=paid
	char mealPreference[50];
	char bookingConfirmation[50];
	char bookingTime[50];
	int booking status;//0=pending,1=confirmed,2=canceled;
	struct bookingDetails *next;
}*book=NULL;
void phoneNumber()
{
	while(1)
	{
		printf("\nPhone Number:");
		scanf("%s",&book->contactDetails);
		if(strlen(book->contactDetails)==10)
		{
			break;
		}
		else
		{
			printf("PLease enter a valid phone number.");
		}
	}
}
void seatType()
{
	while(1)
	{
		printf("Please select your preferred seat type(Enter 0 for Economy,1 for business):")
		scanf("%d",&book->passengerType)
		if(book->passengerType==0 || book->numberOfSeats==1)
		{
			break;
		}
		else
		{
			prinff("inavid enter.Try again.")
		}
	}
}
void fillBookingDetails()
{	
	struct bookingDetails *t,*last;
	book=(struct bookingDetails *)malloc(sizeof(struct bookingDetails));
	printf("to proceed with your booking,kindly specify the number of seats you would like to reserve:");
	scanf("%d",&book->numberOfSeats);
	printf("\nName:");
	fgets(book->name,sizeof(name),stdin);
	phoneNumber();
	printf("\nAge:");
	scanf("%d",book->age);
	seatType();
	
	
	
	
}
void display(struct flightSample *x)
{	
	printf("FLIGHT DETAILS:\n\n");
	printf("| %-15s | %-10s | %-15s | %-15s | %-12s | %-12s | %-12s | %-5s | %-10s | %-15s | %-13s | %-13s | %-17s |\n",
	"Airline","Flight No.","From","Destination","Date","Departure Time","Arrival Time","Gate","Status","Aircraft Type","Economy Seats","Business Seats","Total Available Seats");
	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
	while(x!=NULL)
	{
		printf("| %-15s | %-10s | %-15s | %-15s | %-12s | %-14s | %-12s | %-5s | %-10s | %-15s | %-13d | %-14d | %-21d |\n",
        x->airline,x->flightnumber,"Delhi",x->destination,"24/01/2025",x->departureTime,x->arrivaltime,x->gate,x->status,x->aircraftType,x->economySeats,x->businessSeats,x->seatsAvailable);
        x=x->next;
	}
}
int main()
{
	createFlight();
	display(flight);
	return 0;
}


