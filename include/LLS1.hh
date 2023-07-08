#ifndef LLS1_HH
#define LLS1_HH

#include "LLTypes.hh"
#include "LLOptical.hh"
#include "LLSinglePhotoelectron.hh"
#include "LLConfiguration.hh"
#include <vector>
#include <random>
#include <numeric>


class LLS1 {
    public:
        LLS1(LLConfiguration *pConfig);
        ~LLS1();

        void DrawTimes(std::vector<unsigned int> &uiNgamma,
            std::vector<double> &dStartTimes,
            std::vector<double> &dScintTimes,
            std::vector<unsigned int> &uiInteractionTypes);
        void DrawPhotonsPerChannel(std::vector<unsigned int> &uiNgamma,
            std::vector<double> &dPositions,
            std::vector<unsigned int> &uiPhotonsPerChannel);
        void Simulate(std::vector<unsigned int> &uiNgamma,
            std::vector<double> &dPositions,
            std::vector<double> &dStartTimes,
            std::vector<unsigned int> &sInteractionTypes,
            Hits_t &SimHits);

    private:
        LLConfiguration *m_pConfig;
        LLOptical *m_pOptical;

        std::random_device m_rd;
        std::mt19937_64 m_gen;
        std::exponential_distribution<double> m_LXeSinglet;
        std::exponential_distribution<double> m_LXeTriplet;
        std::uniform_real_distribution<double> m_Uniform;
        std::binomial_distribution<int> m_Binomial;
        
};

#endif