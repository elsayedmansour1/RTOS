/******************************************************************/
/*             >>DATE:15/12/2020                                  */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"../include/BIT_MATH.h"
#include"../include/STD_TYPES.h"
#include"../include/GPIO_Priv.h"
#include"../include/GPIO_INT.h"
#include"../include/SYSTICK_Priv.h"
#include"../include/SYSTICK_INT.h"
#include"../include/RTO_Priv.h"
#include"../include/RTO_INT.h"
#include"../include/RTO_Config.h"

static TCB Array_Of_task[MAX_NUM_OF_TASK];
static u8 Array_Of_Flag[MAX_NUM_OF_TASK];
u8 LOC_u8Counter=0;
void RTO_VidCreateTask(u8 LOC_u8Priority,u16 LOC_u16Periodicity,u16 LOC_u16FirstDelay,void (*LOC_PF)(void))
{
	if( ( LOC_PF!=NULL ) && (LOC_u8Priority<MAX_NUM_OF_TASK) && (Array_Of_Flag[LOC_u8Priority]==0) )
	{
		Array_Of_task[LOC_u8Priority].Priodicity=LOC_u16Periodicity;
		Array_Of_task[LOC_u8Priority].FristDelay=LOC_u16FirstDelay;
		Array_Of_task[LOC_u8Priority].PF=LOC_PF;
		Array_Of_Flag[LOC_u8Priority]=1;
	}
}

static void RTO_VidScheduler(void)
{
	for(LOC_u8Counter=0;LOC_u8Counter<MAX_NUM_OF_TASK;LOC_u8Counter++)
	{

			if(Array_Of_task[LOC_u8Counter].FristDelay==0)
			{
				Array_Of_task[LOC_u8Counter].PF();
				Array_Of_task[LOC_u8Counter].FristDelay=Array_Of_task[LOC_u8Counter].Priodicity-1;

			}
			else
			{
				Array_Of_task[LOC_u8Counter].FristDelay--;
			}


	}
}

void RTO_VidSchedulerINIT(void)
{
	MSTK_VidINIT();
	MSTK_VidSetIntervalPeriodic(RTO_TickTime,RTO_VidScheduler);

}
