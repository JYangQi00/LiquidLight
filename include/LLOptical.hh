#ifndef LLOPTICAL_HH
#define LLOPTICAL_HH

#include "LLConfiguration.hh"
#include "LLGenericMap.hh"
#include "LLConstantMap.hh"

class LLOptical {
    public:
        LLOptical(LLConfiguration *pConfig);
        ~LLOptical();

    private:
        LLConfiguration *m_pConfig;
        unsigned int m_uiNChannels;
        void *m_pHitPatternMap;
        void *m_pLCEMap;
};

#endif