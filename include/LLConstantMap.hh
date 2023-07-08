#ifndef LLCONSTANTMAP_HH
#define LLCONSTANTMAP_HH

#include <vector>

class LLConstantMap {
    public:
        LLConstantMap(unsigned int dimIn, unsigned int dimOut, std::vector<double> &dConstVal)
            : m_uiInDim(dimIn), m_uiOutDim(dimOut) {
                m_dConstVal = dConstVal;
            };
        ~LLConstantMap() {};

        template <typename T>
        void GetValues(std::vector<T> &tPoints, std::vector<T> &tOutPoints) {
            for (int i = 0; i < tPoints.size(); i++){
                for (int j = 0; j < m_uiOutDim; j++){
                    tOutPoints[i*m_uiOutDim + j] = m_dConstVal[j];
                }
            }
        };
    
    private:
        unsigned int m_uiInDim, m_uiOutDim;
        std::vector<double> m_dConstVal;
};

#endif