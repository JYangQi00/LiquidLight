#ifndef LLTYPES_HH
#define LLTYPES_HH

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

typedef struct {
    std::vector<uint16_t> channels;
    std::vector<int64_t> triggerTimes;
    std::vector<int64_t> startTimes;
    std::vector<int64_t> endTimes;
    std::vector<uint16_t> baselines;
    std::vector<std::vector<int>> waveforms;
} Hits_t;

#endif