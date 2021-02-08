#ifndef CLOTHINGCALC_H
#define CLOTHINGCALC_H


class ClothingCalc
{
public:
    // consstructor
    ClothingCalc();
    ClothingCalc(double height, double weight, unsigned int age);



    //Setter
    void setHeight(double height);
    void setWeight(double weight);
    void setAge(unsigned int age);

    // funktioner
    double calcHat();
    double calcJacket();
    double calcWaist();
    unsigned int yearsOverX(unsigned int x, unsigned int fullYears) const;


    //variable
private:
    double mHeight, mWeight;
    unsigned int mAge;


};



#endif // CLOTHINGCALC_H
