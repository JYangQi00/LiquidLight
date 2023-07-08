#ifndef LLELECTROSTATICS_HH
#define LLELECTROSTATICS_HH

#include "GenericMap.hh"
#include "ConstantMap.hh"
#include "RectangularMap.hh"
#include "CylindricalMap.hh"
#include <vector>

class Electrostatics{
    public:
        Electrostatics(std::string& sConfig);
        ~Electrostatics();

        void Drift(double dPoints[], int iNPoints, bool bDiffusion,
            double dFinalPositions[], int iStatus[], double dDt);


        void SetDiffusionConstant(double dLongDiffConst, double dLongDiffConst);
        void SetDiffusionConstant(std::vector<double> dENorm, std::vector<double> dLongDiffConsts, double dTransDiffConsts);
        void SetDiffusionConstant(std::vector<double> dENorm, double dLongDiffConsts, std::vector<double> dTransDiffConsts);
        void SetDiffusionConstant(std::vector<double> dENorm, std::vector<double> dLongDiffConsts, std::vector<double> dTransDiffConsts);

    private:
        
};

#endif