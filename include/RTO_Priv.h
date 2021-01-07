#ifndef  _RTO_PRIVATE_H
#define  _RTO_PRIVATE_H

typedef struct
{
	u8 Priority;
	u16 Priodicity;
	u16 FristDelay;
	void (*PF) (void);
}TCB;

static void RTO_VidScheduler(void);


#endif
