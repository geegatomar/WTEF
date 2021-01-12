#include<bits/stdc++.h>
using namespace std;

class EachFlightData
{
    public:
        string date, person, from, to;

        EachFlightData(string date, string person, string from, string to)
        {
            this->date = date;
            this->person = person;
            this->from = from;
            this->to = to;
        }
};

class EachPersonsFlightDetails
{
        
    public:
        string date, from, to;
        
        EachPersonsFlightDetails(string date, string from, string to)
        {
            this->date = date;
            this->from = from;
            this->to = to;
        }
};

vector<EachFlightData> getFlightsList(int n)
{
    vector<EachFlightData> Flights;
    for(int i = 0; i < n; i++)
    {
        string date, person, from , to;
        cin >> date >> person >> from >> to;
        Flights.emplace_back(date, person, from, to);

        // LEARNING (IMP) --> emplace_back() allows you to directly construct in the container
        // unlike in push_back() you first make the object, and then push its copy to vector
        // EachFlightData nextflight(date, person, from, to);
        // Flights.push_back(nextflight);
    }
    return Flights;
}


map<string, vector<EachPersonsFlightDetails>> getPersonsFlights(vector<EachFlightData> Flights, int n)
{
    map<string, EachPersonsFlightDetails> PersonsFlights;
    for(auto eachFlight : Flights)
    {
        EachPersonsFlightDetails this_flight = EachPersonsFlightDetails(eachFlight.date, eachFlight.from, eachFlight.to);
        PersonsFlights[eachFlight.person].push_back(this_flight);
    }
    return PersonsFlights;
}

bool compareByDate(EachPersonsFlightDetails Details1, EachPersonsFlightDetails Details2)
{
    return Details1.date < Details2.date;                          // sorting by dates
}

bool checkIfRoundTrip(vector<EachPersonsFlightDetails> FlightDetails)
{
    sort(FlightDetails.begin(), FlightDetails.end(), compareByDate);
    
    // now for this person, I have all his trips sorted by dates. Now i need to detect round trip
    // one option is to convert his details to a directed graph then do a dfs (by color trick 0, 1, 2) to detect cycle in directed graph
    
    unordered_set<string> placesVisitedInCurrentContinuousTrip;
    placesVisitedInCurrentContinuousTrip.insert(FlightDetails[0].from);
    for(int i = 1; i < FlightDetails.size(); i++)
    {
        if(FlightDetails[i].from != FlightDetails[i - 1].to)      // if the current flight's from is not equal to the prev flight's to
        {
            placesVisitedInCurrentContinuousTrip.clear();          // clear it because that potential round trip is no more possible since the chain broke
        }

        string currentPlace = FlightDetails[i].to;
        if(placesVisitedInCurrentContinuousTrip.count(currentPlace))       // round trip detected
            return true;
    }
    return false;

    // note: this set approach would work even if other modes of transport are also used
    // and it handles missing data 
}


vector<string> getListOfRoundTripPeople(map<string, vector<EachPersonsFlightDetails>> PersonsFlights)
{
    vector<string> ListOfRoundTripPeople;
    for(auto eachPersonsFlight : PersonsFlights)
    {
        if(checkIfRoundTrip(eachPersonsFlight))
            ListOfRoundTripPeople.push_back(eachPersonsFlight.first);      // .first gives person, .second gives the object
    }
    return ListOfRoundTripPeople;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<EachFlightData> Flights = getFlightsList(n);
    map<string, vector<EachPersonsFlightDetails>> PersonsFlights = getPersonsFlights(Flights, n);
    vector<string> ListOfRoundTripPeople = getListOfRoundTripPeople(PersonsFlights);
    
    for(auto People : ListOfRoundTripPeople)
    {
        cout << People << endl;
    }
}