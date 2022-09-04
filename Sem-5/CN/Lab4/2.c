//cs20b1002
//MANISRIVAS
//GO BACK N CODE
#include<stdio.h>

int main(){
    
    int n,w,df;
    
    printf("enter the number of frames ");
    scanf("%d",&n);
    
    printf("enter the window size ");
    scanf("%d",&w);
    
    printf("enter the drop frame num ");
    scanf("%d",&df);
    
     int fc = 0;
    int pf = 1;

    while (pf <= n)
    {
        if (n - pf < w - 1)
        {
            if ((fc + 1) % df == 0)
            {
                fc = fc + n - pf + 1;
            }
            else
            {
                pf++;
                fc++;
            }
        }
        else
        {
            if ((fc + 1) % df == 0)
            {
                fc = fc + w;
            }
            else
            {
                pf++;
                fc++;
            }
        }
    }
    printf("The total number of frames sent by the sender is: %d\n", fc);
    return 0;
}

// while(++i){
	// 	if(i < nthFrame){
	// 		totalFrames += 1;
	// 		printf("Frame Sent: %d\n", frame);
	// 		frame += 1;
	// 	}else if(i == nthFrame){
	// 		printf("Frame to be Dropped: %d\n", frame);
	// 		if(framesCount - frame + 1 < windowSize){
	// 			totalFrames += 2*(framesCount - frame + 1);
	// 			for(int i = frame; i <= framesCount; i++){
	// 				printf("Frame Sent: %d\n", i);
	// 			}
	// 			break;
	// 		}else if(framesCount - frame + 1 == windowSize){
	// 			totalFrames += 2*(framesCount - frame + 1) + 1;
	// 			for(int i = frame; i < framesCount; i++){
	// 				printf("Frame Sent: %d\n", i);
	// 			}
	// 			printf("Frame to be Dropped: %d\n", framesCount);
	// 			printf("Frame Sent: %d\n", framesCount);
	// 			break;
	// 		}else{
	// 			i += windowSize - 1;
	// 			totalFrames += windowSize;
	// 			nthFrame += droppingFrame;
	// 			printf("i : %d, nth Frame: %d\n", i, nthFrame);
	// 		}
	// 	}
	// }
	