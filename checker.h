
#ifndef _CHKER_H_
#define _CHKER_H_

#define TOTAL_SENS_NO  3
#define MAX_ERR_MSG_LEN  25
#define MAX_CUR_LMT 65535
#define CHK_UPR_LIM(Val,Lim) ((Val > Lim)? 0:1)
#define CHK_LWR_LIM(Val,Lim) ((Val < Lim)? 0:1)



typedef struct Range {
    float Lwr;
    float Upr;
}Range;

typedef struct SensType {
    Range Lim;
    char *ErrMsg[MAX_ERR_MSG_LEN];
}SensType;

#endif