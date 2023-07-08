#include "S1.hh"
#include <random>
#include <numeric>

S1::S1(LLConfiguration *pConfig) {
    m_pConfig = pConfig;
    m_pOptical = new LLOptical(m_pConfig);

    m_gen.seed(m_rd());
    m_LXeSinglet = std::exponential_distribution<double>(m_pConfig->m_dLXeSingletLifetime);
    m_LXeTriplet = std::exponential_distribution<double>(m_pConfig->m_dLXeTripletLifetime);
    m_Uniform = std::uniform_real_distribution<double>(0.0, 1.0);
}

S1::~S1(){
    delete m_pOptical;
}

void DrawPhotonsPerChannel(std::vector<unsigned int> &uiNgamma,
    std::vector<double> &dPositions,
    std::vector<unsigned int> &uiPhotonsPerChannel) {
    
    std::vector<unsigned int> uiSurvivedPhotons;
    uiSurvivedPhotons.reserve(uiNgamma.size());

    int iNph;
    std::vector<double> dLCE(1);
    for (int i = 0; i < uiNgamma.size(); i++){
        m_pOptical->m_pLCEMap->GetValues(dPositions, )
        m_Binomial = std::binomial_distribution<int>(uiNgamma.size(), ) 
    }
}

void S1::DrawTimes(std::vector<unsigned int> &uiNgamma,
    std::vector<double> &dStartTimes,
    std::vector<double> &dScintTimes,
    std::vector<unsigned int> &uiInteractionTypes) {
    
    int iNS1s = uiNgamma.size();
    unsigned int uiNTotalPhotons = std::accumulate(uiNgamma.start(), uiNgamma.end(), 0);
    dScintTimes.reserve(uiNTotalPhotons);

    // std::random_device rd;
    // std::mt19937_64 gen(rd());

    // std::exponential_distribution<double> LXeSinglet(m_pConfig->m_dLXeSingletLifetime);
    // std::exponential_distribution<double> LXeTriplet(m_pConfig->m_dLXeTripletLifetime);
    // std::uniform_real_distribution<double> Uniform(0.0, 1.0);
    double dSingletProbER = (m_pConfig->m_dLXeSingletTripletRatioER)/(1.0+m_pConfig->m_dLXeSingletTripletRatioER);
    double dSingletProbNR = (m_pConfig->m_dLXeSingletTripletRatioNR)/(1.0+m_pConfig->m_dLXeSingletTripletRatioNR);
    double dSingletProb;
    double dPhotonTime;
    double dSingletTripletRand;

    unsigned int uiThisInteraction;
    for (int i = 0; i < iNS1s; i++){
        uiThisInteraction = uiInteractionTypes[i];
        if (uiThisInteraction == 0){
            dSingletProb = dSingletProbER;
        }
        else {
            dSingletProb = dSingletProbNR;
        }

        for (int ph = 0; ph < uiNgamma[i]; ph++){
            dSingletTripletRand = m_Uniform(m_gen);
            if (dSingletTripletRand<dSingletProb) {
                dPhotonTime = dStartTimes[i] + m_LXeSinglet(m_gen);
            }
            else{
                dPhotonTime = dStartTimes[i] + m_LXeTriplet(m_gen);
            }
            dScintTimes.emplace_back(dPhotonTime);
        }
    }
}

void S1::Simulate(std::vector<unsigned int> &uiNgamma,
    std::vector<double> &dPositions,
    std::vector<double> &ulStartTimes,
    std::vector<unsigned int> &uiInteractionTypes,
    Hits_t &SimHits) {
    
    
}