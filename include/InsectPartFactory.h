#ifndef INSECTPARTFACTORY_H
#define INSECTPARTFACTORY_H

#define DEFAULT_INSECT_HP 25
#define DEFAULT_INSECT_LEGSPEED 5
#define DEFAULT_INSECT_INITIVE 150
#define DEFAULT_INSECT_INVENTORY_CAPACITY 25

#include <InsectPartFactoryInterface.h>
#include <Abdomen.h>
#include <Thorax.h>
#include <InsectHead.h>
#include <InsectLeftLeg.h>
#include <InsectRightLeg.h>
#include <vector>

//ack unfortunately an insect robot is different enough that it
//needs its own InsectPartFactoryInterface. I could add
//the createThorax etc... functions to RobotPartFactoryInterface
//but then the worker robots would have to implemnt them also and
//the insect part factory would have to implement all of the regular
//robot methods too.
//Looks like I have to create an Insect part factory interface,
//Insect Part Factory, A Insect Robot Factory with a manufacture
//function that accepts a InsectPartFactory as a parameter.
//This implies that any other kind of robot that is significantly
//different will need these classes also, such as animal robots.
class InsectPartFactory : public InsectPartFactoryInterface
{
    public:
        InsectPartFactory();
        virtual ~InsectPartFactory();
        std::unique_ptr<InsectHead> createInsectHead();
        std::unique_ptr<Thorax> createInsectThorax();
        std::unique_ptr<Abdomen> createInsectAbdomen();
        std::unique_ptr<InsectLeftLeg> createInsectLeftLeg();
        std::unique_ptr<InsectRightLeg> createInsectRightLeg();
        // Should these be here? They are really a collection of legs, they should probably be in InsectRobot.
        std::vector<std::unique_ptr<InsectLeftLeg> > createInsectLeftLegs();
        std::vector<std::unique_ptr<InsectRightLeg> > createInsectRightLegs();
    protected:
    private:
        //std::vector<InsectLeftLeg> leftLegs;
        //std::vector<InsectRightLeg> rightLegs;
};

#endif // INSECTPARTFACTORY_H
