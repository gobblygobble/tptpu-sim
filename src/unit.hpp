#ifndef UNIT_H
#define UNIT_H

#include "common.hpp"

struct request;
typedef struct request request;

class Unit {
public:
    virtual void Cycle() = 0;
    virtual bool IsMainMemory() = 0;
    virtual bool IsMatrixMultiplyUnit() {return false;}
    // for UnifiedBuffer and WeightFetcher
    virtual std::vector<request> *GetSenderQueue() = 0; 
    virtual std::vector<request> *GetServedQueue() = 0;
    virtual std::vector<request> *GetWaitingQueue() = 0;
    virtual std::vector<request> *GetRequestQueue() = 0;
    // for MatrixMultiplyUnit
    virtual std::vector<request> *GetTilingQueue() {assert(0);  return NULL;}
};

#endif /* UNIT_H */
