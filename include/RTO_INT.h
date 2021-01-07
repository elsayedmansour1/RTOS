#ifndef  _RTO_INTERFACE_H
#define  _RTO_INTERFACE_H




void RTO_VidCreateTask(u8 LOC_u8Priority,u16 LOC_u16Periodicity,u16 LOC_u16FirstDelay,void (*LOC_PF)(void));

void RTO_VidSchedulerINIT(void);



#endif
