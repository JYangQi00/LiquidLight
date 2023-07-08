#include "LLOptical.hh"

LLOptical::LLOptical(LLConfiguration *pConfig) {
    m_pConfig = pConfig;

    if (m_pConfig->m_sHitpatternType == "constant"){
        m_pHitPatternMap = new LLConstantMap(m_pConfig->m_uiSpatialDim,
            m_pConfig->m_uiNChannels,
            m_pConfig->m_dHitpatternConstValue);
    }
    else {
        std::cout << "ERROR: Other types of hitpattern maps are not implemented" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (m_pConfig->m_sLCEType == "constant"){
        std::vector<double> LCEConstValue = {m_pConfig->m_dLCEConstValue};
        m_pLCEMap = new LLConstantMap(m_pConfig->m_uiSpatialDim,
            1,
            LCEConstValue);
    }
    else {
        std::cout << "ERROR: Other types of LCE maps are not implemented" << std::endl;
        exit(EXIT_FAILURE);
    }
    
}

LLOptical::~LLOptical() {
    delete m_pHitPatternMap;
    delete m_pLCEMap;
};