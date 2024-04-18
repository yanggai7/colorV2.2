#include "timer.c"

float juqim[4]={210,170,100,200};
float juqir[4]={163,170,100,200};
float juqil[4]={255,170,100,200};
float xfm[4]={215,97,130,200};
float xfz[4]={255,77,200,235};
float xfr[4]={168,77,200,235};
float dz[4]={255,97,187,243};
float dm[4]={215,120,110,200};
float dr[4]={168,97,187,243};
float xm[4]={215,133,100,210};
float xz[4]={255,110,170,240};
float xr[4]={168,110,170,240};
float fangb[4]={100,120,185,255};
float fangr[4]={85,120,185,255};
float fangy[4]={122,120,185,255};
int red[4]={180,155,40,35};
int blue[4]={135,29,43,60};
int yellow[4]={424,178,159,73};

//extern DATA arm1,arm2,arm3,arm4,arm5;
//extern PTDATA parm1,parm2,parm3,parm4,parm5;
//extern COLOR_RGBC red,blue,yellow;

void arm_init(int a){
	TIM_SetCompare1(TIM2,a);
	TIM_SetCompare2(TIM2,a);
	TIM_SetCompare3(TIM2,a);
	TIM_SetCompare4(TIM2,a);
}

void arm_try(int a1,int a2,int a3,int a4){
	TIM_SetCompare1(TIM2,a1);
	TIM_SetCompare2(TIM2,a2);
	TIM_SetCompare3(TIM2,a3);
	TIM_SetCompare4(TIM2,a4);
}

void arm_move(float a1[4],float a2[4]){
	int i;
	float c1=0,c2=0,c3=0,c4=0;
	c1=(a2[0]-a1[0])/75;
	c2=(a2[1]-a1[1])/75;
	c3=(a2[2]-a1[2])/75;
	c4=(a2[3]-a1[3])/75;
	for (i=0;i<75;i++){
		//arm_try((int)(a1[0]+c1*i),(int)(a1[1]+c2*i),(int)(a1[2]+c3*i),(int)(a1[3]+c4*i));
		//TCS34725_GetRawData(&rgb);
		TIM_SetCompare1(TIM2,(int)(a1[0]+c1*i));
		TIM_SetCompare2(TIM2,(int)(a1[1]+c2*i));
		TIM_SetCompare3(TIM2,(int)(a1[2]+c3*i));
		TIM_SetCompare4(TIM2,(int)(a1[3]+c4*i));
		delay_ms(10);
	}
}

int color(void){
//	extern int red[4];
//	extern int blue[4];
//	extern int yellow[4];
	TCS34725_GetRawData(&rgb);
	if (rgb.c>=200&&rgb.r>100&&rgb.g<150&&rgb.b<100){
		return 1;//ºìÉ«
	}
	else if(rgb.c>=150&&rgb.c<=200&&rgb.r<=100&&rgb.g<=100&&rgb.b<=120){
		return 2;//À¶É«
	}
	else if(rgb.c>=350&&rgb.r>=200&&rgb.g>=150&&rgb.b<150){
		return 3;//»ÆÉ«
	}
	else{
		return 0;//Î´¼ì²âµ½
	}
}

int get(int po){//1£º×ó  2£ºÖÐ  3£ºÓÒ
//	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 1){
	if(1){
		if(po==2){
			arm_move(juqim,xm);
			GPIO_SetBits(GPIOA,GPIO_Pin_4);
			if (color()!=0){
				if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				delay_ms(200);
				arm_move(xm,juqim);
				GPIO_SetBits(GPIOA,GPIO_Pin_9);
				return 1;
			}
			else{
				arm_move(xm,dm);
				if (color()!=0){
					if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
					delay_ms(200);
					arm_move(dm,juqim);
					GPIO_SetBits(GPIOA,GPIO_Pin_9);
					return 1;
				}
				else{
					arm_move(dm,xfm);
					if(color()!=0){
						if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
						delay_ms(200);
						arm_move(xfm,juqim);
						GPIO_SetBits(GPIOA,GPIO_Pin_9);
						return 1;
					}
				}
			}
		}
		else if(po==1){
			arm_move(juqim,juqil);
			arm_move(juqil,xz);
			GPIO_SetBits(GPIOA,GPIO_Pin_4);
			if (color()!=0){
				if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				delay_ms(200);
				arm_move(xz,juqim);
				GPIO_SetBits(GPIOA,GPIO_Pin_9);
				return 1;
			}
			else{
				arm_move(xz,dz);
				if (color()!=0){
					if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
					delay_ms(200);
					arm_move(dz,juqim);
					GPIO_SetBits(GPIOA,GPIO_Pin_9);
					return 1;
				}
				else{
					arm_move(dz,xfz);
					if(color()!=0){
						if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
						delay_ms(200);
						arm_move(xfz,juqil);
						GPIO_SetBits(GPIOA,GPIO_Pin_9);
						return 1;
					}
				}
			}
		}
		else if(po==3){
			arm_move(juqim,juqir);
			arm_move(juqir,xr);
			GPIO_SetBits(GPIOA,GPIO_Pin_4);
			if (color()!=0){
				if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				delay_ms(200);
				arm_move(xr,juqim);
				GPIO_SetBits(GPIOA,GPIO_Pin_9);
				return 1;
			}
			else{
				arm_move(xr,dr);
				if (color()!=0){
					if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
					delay_ms(200);
					arm_move(dr,juqim);
					GPIO_SetBits(GPIOA,GPIO_Pin_9);
					return 1;
				}
				else{
					arm_move(dr,xfr);
					if(color()!=0){
						if(color()==1){//ºì
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==2){//À¶
					GPIO_ResetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
				else if(color()==3){//»Æ
					GPIO_SetBits(GPIOA,GPIO_Pin_6);
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
				}
						delay_ms(200);
						arm_move(xfm,juqir);
						GPIO_SetBits(GPIOA,GPIO_Pin_9);
						return 1;
					}
				}
			}
		}
		
	}
}