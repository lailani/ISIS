#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

class CImage{
    int img[100000];
    int mx, my;

    public:

    CImage(int w, int h) {
        mx = w;
        my = h;
    }

    int getMx() {
        return mx;
    }

    int getMy() {
        return my;
    }

    void setColor(int x, int y, int c){
        img[x+y*(mx)] = c;
    }

    int get(int x, int y){

        if ((x<mx)&&(y<my)){
            return img[x+y*(mx)];

        }else
            return 0;
    }
    void show(){
        int i,j = 0;
        for (j = 0; j < getMy(); ++j) {
            for (i = 0; i < getMx(); ++i) {
                printf("%d " , get(i,j));
            }
            printf("\n");
        }
    }


};


    int testCImageMxMy(){
        CImage *a = new CImage(20,10);
        if ((a->getMx()==20)&&(a->getMy()==10)){
            return 1;

        }else
            return 0;

    }

    int testCImageget(){
        CImage *b = new CImage(20,10);
        int i,j;

        for (i = 0; i <b->getMx(); ++i) {
            for (j = 0; j < b->getMy(); ++j) {
                if((b->get(i, j))== 0 ){
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }


    int testCImagepoint(){
        CImage *d = new CImage (20,10);
        d->setColor(5, 7, 1);
        if (d->get(5, 7)==1){
            return 1;
        }else{
            return 0;
        }
    }

    int testCImagepointFail(){
        CImage *d = new CImage (20,10);
        d->setColor(50, 75, 10000);
        if (d->get(50, 75)==10000){
            return 1;
        }else{
            return 0;
        }
    }

    void drawLine(int hbox, int wbox, int rowCount, int colCount , int *number_column_array ){
        // int rowCount=4;
        // int colCount = 4;
        // int wbox = 3;
        // int hbox = 3;

        
        int sizeBox = 3;
        CImage *picture = new CImage((wbox*colCount+colCount+1),(hbox*rowCount+rowCount+1));
        int i,j;
        for (i = 0; i <picture->getMx(); ++i) {
            for (j = 0; j < picture->getMy(); ++j) {
                if((j%(hbox+1)==0) || (i%(wbox+1)==0)){
                    picture->setColor(i, j, 1);
                }
            }
        }
        // picture->show();
        // printf("\n");

        //закрашивание
 
        printf("P1\n");
        printf("%d %d\n", wbox*colCount+colCount+1,hbox*rowCount+rowCount+1);
     
        for (int number_row = 0; number_row < rowCount ; ++number_row)
        {
                for (i = 0; i <picture->getMx(); ++i) {
                    for (j = 0; j < picture->getMy(); ++j) {
                        if((i>(1+wbox)*(*(number_column_array+number_row)-1)) && (i<(1+wbox)*(*(number_column_array+number_row)-1)+1 + hbox) && (j>(1+hbox)*(number_row)) && (j<(1+hbox)*(number_row)+1 + hbox)  )     {
                            picture->setColor(i, j, 7);
                        }
                    }
                }
            
        }
        // picture->setColor((1+sizeBox)*(3-1)+1,(1+sizeBox)*(2-1)+1,5);
        picture->show();
    }

    char *int2bin(int a, char *buffer, int buf_size){
        buffer += (buf_size-1);

        for (int i = 31; i >= 0; i--)
        {
            *buffer --= (a&1) + '0';

            a >>=1;
        }
        return buffer;

    }




    int main(int argc,char* argv[]){

        // CImage *p = new CImage(20,10);
        // p->show();


        // if (testCImageMxMy()==1){
        //     printf("Test OK\n");
        // }else
        //     printf("Test Fail\n");

        // if (testCImageget()==1){
        //     printf("Test OK\n");
        // }else
        //     printf("Test Fail\n");

        // if (testCImagepoint()==1){
        //     printf("Test OK\n");
        // }else
        //     printf("Test Fail\n");

        // if (testCImagepointFail()==1){
        //     printf("Test OK\n");
        // }else
        //     printf("Test Fail\n");

        /*int rowCount=2;
        int colCount = 3;
        int sizeBox = 5;

        CImage *picture = new CImage((sizeBox*colCount+colCount+1),(sizeBox*rowCount+rowCount+1));
        picture->show();

       */

        
        int number_column_array[argc-4];
        int number;
        char buffer[33];
        buffer[32] = '\0';
        

        for (int i = 5; i < (argc); ++i)

        {
            number = (int)strtol(argv[i], NULL, 0);
            int2bin(number, buffer , 32 );
            for (int j = 32; j > 0; j--)
            {
                if (buffer[j] == '1')
                {
                    number_column_array[i-5] = 32-j;
                    break;
                }
            }



        }

        drawLine(atoi(argv[1]) ,atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), number_column_array);



        return 0;
    }