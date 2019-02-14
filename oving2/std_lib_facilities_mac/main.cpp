#include "std_lib_facilities.h"
#include "loan_drawer.h"


void inputAndPrintInteger(){
    int num;
    cout << "Skriv inn et tall: ";
    cin >> num;
    cout << "Du skrev: " << num << "\n";
}

int inputInteger(){
    int num;
    cout << "Skriv inn et tall: ";
    cin >> num;
    return num;
}

void inputIntegersAndPrintSum(){
    int num1 = inputInteger();
    int num2 = inputInteger();
    cout << "Summen av tallene: " <<  num1 + num2 << endl;
}

// Bruker inputInteger() fordi funksjonen returner en verdi isteden for å skrive til konsollen

bool isOdd(int num){
    if (num%2!=0){
        return true;
    }
    return false;
}



void printHumanReadableTime(int timeSecs){
    int hours = timeSecs / 3600;
    int minutes = (timeSecs - hours * 3600) / 60;
    int seconds = (timeSecs - hours * 3600 - minutes * 60);
    cout << hours << " timer, " << minutes << " minutter, " << seconds << " sekunder." << endl;
}

void inputIntegersUsingLoopAndPrintSum(){
    int cont = 1;
    while (cont == 1){
        inputIntegersAndPrintSum();
        cout << "Ønsker du å fortsette? (0/1)? ";
        cin >> cont;
    }
}

// For det første bruksområdet egner det seg best med en for-loop, mens for den andre egner det seg best med en while-loop.

double inputDouble(){
    double num;
    cout << "Skriv inn et tall: ";
    cin >> num;
    return num;
}

void euroToNOKConverter(){
    bool positive = false;
    
    while (not positive){
        int price;
        constexpr double conversionRate = 9.75;
        cout << "Skriv inn summen du ønsker å konvertere: ";
        cin >> price;
        
        if (price > 0){
            cout << setprecision(2) << fixed;
            cout << "Pris i NOK: " << conversionRate * price << "\n";
            positive = true;
        } else{
            cout << "Skriv inn en positiv sum \n";
        }
    }
}

// Det er bedre å bruke inputDouble() ettersom den ikke krever at summen som skal konverteres er er heltall. Funksjonen returner en double.

void printMultiplication(){
    int width;
    int height;
    cout << "Skriv inn bredden til gangetabellen: ";
    cin >> width;
    cout << "\nSkriv inn høyden til gangetabellen: ";
    cin >> height;
    for (int i = 1; i < height + 1; i++){
        for (int j = 1; (j < width+1); j++){
            cout << setw(5) << i*j;
        }
        cout << endl;
    }
}

double discriminant(double a, double b, double c){
    return pow(b, 2)-4*a*c;
}

void printRealRoots(double a, double b, double c){
    int disc = discriminant(a, b, c);
    if (disc == 0){
        cout << fixed << setprecision(5);
        cout << "Løsning: " << -b/(2*a) << endl;
    } else if (disc > 0){
        double sol1 = (-b+sqrt(disc))/(2*a);
        double sol2 = (-b-sqrt(disc))/(2*a);
        cout << fixed << setprecision(5);
        cout << "Løsninger: " << sol1 << "\t" << sol2 << endl;
    } else{
        cout << "Ingen reelle løsninger. " << endl;
    }
}

void solveQuadraticEquation(){
    int a;
    int b;
    int c;
    cout << "Skriv inn det første tallet: ";
    cin >> a;
    cout << "\nSkriv inn det andre tallet: ";
    cin >> b;
    cout << "\nSkriv inn det tredje tallet: ";
    cin >> c;
    cout << endl;
    printRealRoots(a, b, c);
}

vector<int> calculateSeries(int antallAar, int totaltLan, double rente){
    vector<int> series;
    
    for (int i = 0; i < antallAar; i++){
        int avdrag = totaltLan/antallAar;
        int gjenstaende = totaltLan - avdrag * i;
        series.push_back(avdrag + int((rente/100.0)*gjenstaende));
    }
    return series;
}

vector<int> calculateAnnuity(int antallAar, int totaltLan, double rente){
    vector<int> annuity;
    for (int i = 0; i < antallAar; i++){
        annuity.push_back(totaltLan*((rente/100.0)/(1-pow(((1+rente/100.0)), -antallAar))));
    }
    return annuity;
}


void comparePricing(){
    int aar = 10;
    int lan = 1000000;
    double rente = 2.0;
    
    vector<int> series = calculateSeries(aar, lan, rente);
    vector<int> annuity = calculateAnnuity(aar, lan, rente);
    
    cout << setw(3) << "År " << "Annuitet " << "Serie " << "Differanse " << endl;
    for (int i = 0; i < aar; i++){
        cout << setw(2) << i+1 << setw(2) << " " << setw(3) << annuity[i] << " " << setw(4) << series[i] << " " << setw(10) << abs(annuity[i]-series[i]) << endl;
        
    }
}

int main(){
    /*
    cout << "Velg funksjon: \n 0) Avslutt \n 1) Summer to tall \n 2) Summer flere tall \n 3) Konverter Euro til NOK \n 4) Se gangetabell med gitt høyde og bredde \n 5) Løs andregradsuttrykk \n 6) Sammenlikn lån \n";
    int choice;
    cout << "Angi valg (0-6): ";
    cin >> choice;
    while (choice != 0){
        switch(choice){
            case 0:
                break;
            case 1:
                inputIntegersAndPrintSum();
                break;
            case 2:
                inputIntegersAndPrintSum();
                break;
            case 3:
                euroToNOKConverter();
                break;
            case 4:
                printMultiplication();
                break;
            case 5:
                solveQuadraticEquation();
                break;
            case 6:
                comparePricing();
                break;
            default:
                break;
        }
        if (choice != 0){
            cout << "\nVelg funksjon: \n 0) Avslutt \n 1) Summer to tall \n 2) Summer flere tall \n 3) Konverter Euro til NOK \n 4) Se gangetabell med gitt høyde og bredde \n 5) Løs andregradsuttrykk \n 6) Sammenlikn lån \n";
            cout << "Angi valg (0-6): ";
            cin >> choice;
        }
    }
    */
    vector<int> annuity = calculateAnnuity(10, 3000, 10);
    vector<int> series = calculateSeries(10, 3000, 10);
    drawPlot(annuity, series, 3000, 10);
    return 0;
}
