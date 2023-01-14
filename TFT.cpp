#include <iostream>
#include <string>
using namespace std;
struct Champion
{
    string name;
    int attackDamage,abilityPower,healthPoints,mana,armor,resistance,abilityUsed;
    float attackSpeed;
    int ablility()
    {
        return (abilityPower);
    }; 
    
    int howManyAttacks(int time)
    {
        return (time * attackSpeed);
    }
    
    int damageTaken(int adDmgTaken, int apDmgTaken)
    {
        
        return (adDmgTaken *(0.15*armor) + apDmgTaken *(0.2 * resistance)) ;
    } 
    
    void useAbility()
    {
        ablility();
        abilityUsed++;
    }

};

void fight (struct Champion One,struct Champion Two,int time)
{
    for (int i = 0; i < time; i++)
    {
        if (One.abilityUsed == 0 && Two.abilityUsed == 0)
        {
            if ((One.howManyAttacks(i) * 10) + ((7/100) * One.damageTaken(One.howManyAttacks(i)*One.attackDamage,0) ) == Two.mana)
            {
                Two.useAbility();
            }
            else if (((Two.howManyAttacks(i) * 10) + ((7/100) * Two.damageTaken(Two.howManyAttacks(i)*Two.attackDamage,0) ) ) == One.mana)
            {
                One.useAbility();
            }
        }
        else
        {
            if ((Two.howManyAttacks(i) * 10) + ((7/100) * Two.damageTaken(One.howManyAttacks(i)*One.attackDamage,(One.ablility()*One.abilityUsed)) ) == Two.mana * Two.abilityUsed)
            {
                Two.useAbility();
            }
            else if (((One.howManyAttacks(i) * 10) + ((7/100) * One.damageTaken(Two.howManyAttacks(i)*Two.attackDamage,(Two.ablility()*Two.abilityUsed)) ) ) == (One.mana) * One.abilityUsed)
            {
                One.useAbility();
            }
        }

        if (One.damageTaken(Two.howManyAttacks(i)*Two.attackDamage,(Two.ablility()*Two.abilityUsed)) >= One.healthPoints || Two.damageTaken(One.howManyAttacks(i)*One.attackDamage,(One.ablility()*One.abilityUsed)) >= Two.healthPoints)
        {
            if (One.damageTaken(Two.howManyAttacks(i)*Two.attackDamage,(Two.ablility()*Two.abilityUsed)) >= One.healthPoints)
            {
                cout << One.name << " died after " << i << " s of battle" << endl ;
                break;
            }
            else
            {
                cout << Two.name << " died after " << i << " s of battle" << endl ;
                break;
            }
        }
    }
    cout << Two.name << " have " << (Two.healthPoints - Two.damageTaken(One.howManyAttacks(time)*One.attackDamage,(One.ablility()*One.abilityUsed)))<< "HP after "<< time<< " s of fight" << endl;
    cout << One.name << " have " << (One.healthPoints - One.damageTaken(Two.howManyAttacks(time)*Two.attackDamage,(Two.ablility()*Two.abilityUsed)))<< "HP after "<< time<< " s of fight" << endl;
};

int main()
{
    Champion Zoe;
    Champion Senna;
    Senna.name ="Senna";
    Senna.attackDamage = 70;
    Senna.abilityPower = 175;
    Senna.healthPoints = 650;
    Senna.mana = 70;
    Senna.armor = 25;
    Senna.resistance = 25;
    Senna.abilityUsed = 0;
    Senna.attackSpeed = 0.7;

    Zoe.name ="Zoe";
    Zoe.attackDamage = 40;
    Zoe.abilityPower = 200;
    Zoe.healthPoints = 850;
    Zoe.mana = 30;
    Zoe.armor = 20;
    Zoe.resistance = 20;
    Zoe.abilityUsed = 0;
    Zoe.attackSpeed = 0.7;

    fight(Zoe,Senna,3);
    fight(Zoe,Senna,6);
    fight(Zoe,Senna,10);

}