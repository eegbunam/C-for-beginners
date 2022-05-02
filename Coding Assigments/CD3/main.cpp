#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>



class GasPrice {
    public: 
        GasPrice(double price , int month , int year , int day)
        {
            this->price = price;
            this->month = month;
            this->year = year;
            this->day = day;
        }
        bool operator < (const GasPrice& other) const
        {
            return (price < other.price);
        }
        
        std::string print()
        {
            std::stringstream ss;
            ss << "Price: " << price << " Month: " << month << " Year: " << year << " Day: " << day;
            return ss.str();
        }


    private: 
        double price;
        int month;
        int year;
        int day;



};

using namespace std;

typedef unordered_map<string, vector<double> > umap;

 void readFileIntoStructures( string fileName ,umap &Ymap , umap  &Mmap , std::vector<GasPrice> &gasPrices)
{
    ifstream myFileStream(fileName);
    string line;

    if (!myFileStream.is_open())
    {
        cout << "File not found" << endl;
        return;
    }

    string date , gasPrice;

    while(getline(myFileStream , line))
    {
        string day , month , year;
        stringstream ss(line);
        getline(ss , date , ':');
        getline(ss , gasPrice);
        day = date.substr(0,2);
        month = date.substr(3,2);
        year = date.substr(6,4);
       // cout << "day: " << day << " month: " << month << " year: " << year << " gasPrice: " << gasPrice << endl;
        Ymap[year].push_back(stod(gasPrice));
        Mmap[month].push_back(stod(gasPrice));
        gasPrices.push_back(GasPrice(stod(gasPrice) , stoi(month) , stoi(year) , stoi(day)));
    }
    gasPrices[0].print();


 
    myFileStream.close();
}

void getHighesAndLowestProcePerYear( umap &Ymap )
{
   
    for(auto it = Ymap.begin(); it != Ymap.end(); it++)
    {
        double lowestPrice = *std::min_element(it->second.begin() , it->second.end());
        double highestPrice = *std::max_element(it->second.begin() , it->second.end());
        cout << "Year: " << it->first << " Lowest Price: " << lowestPrice << " Highest Price: " << highestPrice << endl;
    }
    
}

void getAveragePerMonth( umap &Mmap )
{
    for(auto it = Mmap.begin(); it != Mmap.end(); it++)
    {
        double sum = 0;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            sum += *it2;
        }
        double average = sum / it->second.size();
        cout << "Average price for month " << it->first << " is: $" << average << endl;
    }
}

void createLeasttoHighestPriceFile( std::vector<GasPrice> &gasPrices)
{
    std::sort(gasPrices.begin() , gasPrices.end());
    ofstream myFileStream("leastToHighest.txt");
    if (!myFileStream.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    for(auto it = gasPrices.begin(); it != gasPrices.end(); it++)
    {
        myFileStream << it->print() << endl;
    }
    myFileStream.close();
}

void createHighestToLeastPriceFile( std::vector<GasPrice> &gasPrices)
{
    std::sort(gasPrices.begin() , gasPrices.end());
    std::reverse(gasPrices.begin() , gasPrices.end());
    ofstream myFileStream("highestToLeast.txt");
    if (!myFileStream.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    for(auto it = gasPrices.begin(); it != gasPrices.end(); it++)
    {
        myFileStream << it->print() << endl;
    }
    myFileStream.close();
}




int main(){

    umap  Ymap;
    umap  Mmap;
    std::vector<GasPrice> gasPrices;
    void readFileIntoStructures( string fileName ,umap &Ymap , umap  &Mmap , std::vector<GasPrice> &gasPrices);
    readFileIntoStructures("gasPrices.txt" , Ymap , Mmap , gasPrices);
    void createHighestToLeastPriceFile( std::vector<GasPrice> &gasPrices);
    void createLeasttoHighestPriceFile( std::vector<GasPrice> &gasPrices);
    void getHighesAndLowestProcePerYear( umap &Ymap );

    getHighesAndLowestProcePerYear(Ymap);
    getAveragePerMonth(Mmap);

    createLeasttoHighestPriceFile(gasPrices);
    createHighestToLeastPriceFile(gasPrices);



   


   
           

    

   

    return 0;

}