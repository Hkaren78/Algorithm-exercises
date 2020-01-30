class Solution 
{
	public:    
	#define INT_MAX 2147483647    
	#define INT_MIN (-INT_MAX-1)    
	int reverse(int x) 
	{        
		int flag=x<0?-1:1;        
		int num=0;        
		while(x){            
			if((flag==-1&&(INT_MIN/10>num))||(flag==1&&INT_MAX/10<num))
				return 0;            
			num=num*10+x%10;            
			x/=10;        
		}        
		return num;    
	}
};

