//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_ADC.c
//功能概要：BSP_ADC驱动文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <math.h>
#include "adc.h"
#include "BSP_ADC.h"

extern unsigned int ADC_Value[3];
extern float VOL_Value[3];

//=============================================================================
//文件名称：void GPIO_ADC_Init(ADC_HandleTypeDef* adcHandle)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GPIO_ADC_Init(ADC_HandleTypeDef* adcHandle)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**ADC1 GPIO Configuration    
    PA0-WKUP     ------> ADC1_IN0
    PA1     ------> ADC1_IN1
    PA4     ------> ADC1_IN4 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* ADC1 interrupt Init */
    HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ADC1_2_IRQn);
  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
}

//=============================================================================
//文件名称：void Goble_MX_ADC1_Init(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void Goble_MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = ENABLE;
  hadc1.Init.NbrOfDiscConversion = 1;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;//3
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
#if 0
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
#endif
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

//=============================================================================
//文件名称：unsigned char READ_LIGHT_AD(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned char READ_LIGHT_AD(void)
{
		unsigned char i;
		float f;
		unsigned int k;
	
		//i=Get_Adc_Average(8,18);
		f=(float)i;
		f*=1.65;		//鏀逛负瀵瑰簲鍙傝�冪數鍘嬩负2V鐨凙D鍊?-鐏帶鏉緼D鍙傝�冪數鍘嬩负2V
		k=(unsigned int)f;
		
		if(k>255)k=255;
		i=k;
		return(i);
}

//=============================================================================
//文件名称：unsigned int Get_Adc0(unsigned char ch)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned int Get_Adc0(unsigned char ch)
{
	/*
  	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_13Cycles5 );	//ADC1,ADC通道,采样时间为7.5+12.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果

	*/
	//unsigned int i = 0;
	unsigned int j = 0;
	unsigned long ADC_V[3];
	//float VOL_V[3];
	
	for(j=0;j<3;j++)
	{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,0xffff);
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
		{
			ADC_V[j] +=HAL_ADC_GetValue(&hadc1);
			//VOL_V[i] = (float)(ADC_V[i]&0xFFF)*3.3/4096;
			//printf("------ch:%d--%d--%f V -----\r\n",i,ADC_V[i],VOL_V[i]);
		}
	}
	
	HAL_ADC_Stop(&hadc1);

	printf("------ch:%d--%d--%f V -----\r\n",ch,ADC_V[ch],(float)(ADC_V[j]&0xFFF)*3.3/4096);
	printf("--------------------------------------------\r\n");
	
	return ADC_V[ch];

}

//=============================================================================
//文件名称：unsigned int Get_Adc(unsigned char ch)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned int Get_Adc(unsigned char ch)
{
	/*
  	//设置指定ADC的规则组通道，一个序列，采样时间
//	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_13Cycles5 );	//ADC1,ADC通道,采样时间为7.5+12.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
	*/
	//unsigned int i = 0;
	//unsigned int j = 0;
	unsigned long ADC_V;
	//float VOL_V[3];
	
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,0xffff);
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
	{
		ADC_V =HAL_ADC_GetValue(&hadc1);
		//VOL_V[i] = (float)(ADC_V[i]&0xFFF)*3.3/4096;
		//printf("------ch:%d--%d--%f V -----\r\n",i,ADC_V[i],VOL_V[i]);
	}

	HAL_ADC_Stop(&hadc1);

	//printf("------ch:%d--%d--%f V -----\r\n",ch,ADC_V,(float)(ADC_V&0xFFF)*3.3/4096);
	//printf("--------------------------------------------\r\n");
	
	return ADC_V;
}

//=============================================================================
//文件名称：unsigned char Get_Adc_Average(unsigned char ch,unsigned int times)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned char Get_Adc_Average(unsigned char ch,unsigned int times)
{
	/*
	u32 temp_val=0;
	u16 ad_val=0,ad_max=0,ad_min=0xfff;
	u16 t,t1;//,i,j;
	
	Get_Adc0(ch);
		t1=200;
		while(t1--);	
	
	for(t=0;t<times;t++)
	{
		t1=15;
		while(t1--);
		
		//temp_val+=Get_Adc(ch);
		ad_val=Get_Adc(ch);
		temp_val+=ad_val;
		if(ad_max<ad_val)ad_max=ad_val;
		if(ad_min>ad_val)ad_min=ad_val;		
	}

	temp_val-=ad_max;
	temp_val-=ad_min;
	
	times-=2;
	temp_val/=times;
	t=temp_val>>4;
	
	return t;
	*/
	
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned long ADC_V[3];
	//float VOL_V[3];
	
	for(i=0;i<times;i++)
	{
		for(j=0;j<3;j++)
		{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1,0xffff);
			if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
			{
				ADC_V[j] +=HAL_ADC_GetValue(&hadc1);
				//VOL_V[i] = (float)(ADC_V[i]&0xFFF)*3.3/4096;
				//printf("------ch:%d--%d--%f V -----\r\n",i,ADC_V[i],VOL_V[i]);
			}
		}
		HAL_ADC_Stop(&hadc1);
	}
	
	
	for(j=0;j<3;j++)
	{
		ADC_Value[j] = ADC_V[j] / times;
		//VOL_Value[j] = (float)(ADC_Value[j]&0xFFF)*3.3/4096;
		//printf("------ch:%d--%d--%f V -----\r\n",j,ADC_Value[j],VOL_Value[j]);
	}
	//printf("--------------------------------------------\r\n");
	
	return ADC_Value[ch];

} 	 

//=============================================================================
//文件名称：void Get_Adc_Average_All(unsigned int times)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void Get_Adc_Average_All(unsigned int times)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned long ADC_V[3]={0};
	//float VOL_V[3];
	//__disable_irq();//关

	for(i=0;i<times;i++)
	{
		for(j=0;j<3;j++)
		{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1,0xffff);
			//HAL_ADC_PollForConversion(&hadc1,10);
			//if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
			{
				ADC_V[j] +=HAL_ADC_GetValue(&hadc1);
				//VOL_V[i] = (float)(ADC_V[i]&0xFFF)*3.3/4096;
				//printf("------ch:%d--%d--%f V -----\r\n",i,ADC_V[i],VOL_V[i]);
			}
		}
		HAL_ADC_Stop(&hadc1);
	}
	
	
	for(j=0;j<3;j++)
	{
		ADC_Value[j] = ADC_V[j] / times;
		//VOL_Value[j] = (float)(ADC_Value[j]&0xFFF)*3.3/4096;
		//printf("------ch:%d--%d--%f V -----\r\n",j,ADC_Value[j],VOL_Value[j]);
	}
	//printf("--------------------------------------------\r\n");
	//__enable_irq();//打开中断全能
}

//=============================================================================
//文件名称：unsigned int Get_ADC_Value(unsigned char ch,unsigned char times)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned int Get_ADC_Value(unsigned char ch,unsigned char times)
{
/*
	unsigned char t;
	unsigned char temp_val=0;

	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5); //鏈�澶х殑杞崲鍛ㄦ湡锛?39.5涓?
	HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig)
	for (t=0;t<10;t++)
	{
		ADC_SoftwareStartConvCmd(ADC1,ENABLE); 
		while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));  //杞崲瀹屾垚鍚庨��鍑?
		temp_val+=ADC_GetConversionValue(ADC1);
		delay_ms(5);
	}
	return temp_val/times;
	*/
	
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned long ADC_V[3];
	//float VOL_V[3];
	
	for(i=0;i<times;i++)
	{
		for(j=0;j<3;j++)
		{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1,0xffff);
			if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
			{
				ADC_V[j] +=HAL_ADC_GetValue(&hadc1);
				//VOL_V[i] = (float)(ADC_V[i]&0xFFF)*3.3/4096;
				//printf("------ch:%d--%d--%f V -----\r\n",i,ADC_V[i],VOL_V[i]);
			}
		}
		
		HAL_ADC_Stop(&hadc1);

	}

	
	for(j=0;j<3;j++)
	{
		ADC_Value[j] = ADC_V[j] / times;
		VOL_Value[j] = (float)(ADC_Value[j]&0xFFF)*3.3/4096;
		printf("------ch:%d--%d--%f V -----\r\n",j,ADC_Value[j],VOL_Value[j]);
	}
	printf("--------------------------------------------\r\n");
	
	return ADC_Value[ch];
}

//=============================================================================
//文件名称：unsigned int Get_Adc__(unsigned int ch)  
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned int Get_Adc__(unsigned int ch)   
{
    ADC_ChannelConfTypeDef  ADC1_ChanConf;
   
    ADC1_ChanConf.Channel=ch;                                       ADC1_ChanConf.Rank=1;                                      
    ADC1_ChanConf.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;      //2é?ùê±??               
    HAL_ADC_ConfigChannel(&hadc1,&ADC1_ChanConf);        //
    HAL_ADC_Start(&hadc1);                               //?a??ADC
   
    HAL_ADC_PollForConversion(&hadc1,10);                 
    return (unsigned int)HAL_ADC_GetValue(&hadc1);            
}



//temp_val鐨勫彇鍊艰寖鍥存槸0-4095锛屽洜姝ゅ簲瀹氫箟涓?2浣嶇殑鍙橀噺锛歶8 temp_val=0鈫抲32 temp_val=0;
//閽堝HAL搴撲腑绋嬪簭锛屼竴瀹氳瀹氫箟VOL_Value涓烘诞鐐瑰瀷鐨勩�?
//
#if 0
杞妯″紡聽-- 闈為樆濉?聽 聽
//##-3- Start the conversion process ######/
if(HAL_ADC_Start(&AdcHandle) != HAL_OK)
{ Error_Handler(); }
//##-4- Wait for the end of conversion ######/
HAL_ADC_PollForConversion(&AdcHandle, 10);
if(HAL_ADC_GetState(&AdcHandle) == HAL_ADC_STATE_EOC_REG)
{
//##-5- Get the converted value of channel ##
uhADCxConvertedValue = HAL_ADC_GetValue(&AdcHandle);
}
涓柇妯″紡
//##-3- Start the conversion process ######/
if(HAL_ADC_StartIT(&AdcHandle) != HAL_OK)
{ Error_Handler(); }
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{ /* Get the converted value of regular channel */
uhADCxConvertedValue = HAL_ADC_GetValue(AdcHandle);
}
DMA妯″紡
//##-3- Start the conversion process ######/
if(HAL_ADC_StartDMA(&AdcHandle,&uhADCxConvertedValue,1) != HAL_OK)
{ Error_Handler(); }
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{ // Turn LED1 on: Transfer process is correct 
BSP_LED_On(LED1);
}

#endif
