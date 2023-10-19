//FCAI - OOP programing - 2023 - Assignment 1
// Program: demo2.cpp
// Author1 and ID : Mazen Abdelfattah - 20230607     //I was having no ID ,so I act like the Smallest ID(as the professor said)
// Author2 and ID : Malak Khattab - 20210403         //middle ID
// Author3 and ID : Gehad Shaban - 20220535          //biggest ID
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file

#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"
#include<cmath>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void menu();
void loadImage();
void saving_image();
void black_white();
void invert();
void merge();
void flip();
void rotate();
void darken_lighten();
void detect_edges();
void enlarge();
void shrink();
void mirror();
void shuffle();
void blur();
void crop();
void skewHorizontally();
void skewVertically();

int main()
{
    bool flag = true;
    while (flag)
    {
        int check;
        cout << "do u want to continue to the program\n1 ->true\n2 ->false\nenter:";
        cin >> check;
        if (check == 1) {
            menu();
        }
        else {
            flag = false;
        }
    }

    return 0;
}

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saving_image() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);

}

void menu() {
    char choice;
    cout << "Enter the number of the filter" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "black & white       ||                        1" << endl;
    cout << "invert              ||                        2" << endl;
    cout << "merge               ||                        3" << endl;
    cout << "flip                ||                        4" << endl;
    cout << "rotate              ||                        5" << endl;
    cout << "darken & lighten    ||                        6" << endl;
    cout << "detect edges        ||                        7" << endl;
    cout << "enlarge             ||                        8" << endl;
    cout << "shrink              ||                        9" << endl;
    cout << "mirror              ||                        a" << endl;
    cout << "shuffle             ||                        b" << endl;
    cout << "blur                ||                        c" << endl;
    cout << "crop                ||                        d" << endl;
    cout << "skewHorizontally    ||                        e" << endl;
    cout << "skewVertically      ||                        f" << endl;
    cout << "exit                ||                        x" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Enter the Number:";
    cin >> choice;
    switch (choice)
    {
        case '1':
            loadImage();
            black_white();
            saving_image();
            break;
        case '2':
            loadImage();
            invert();
            saving_image();
            break;
        case '3':
            loadImage();
            merge();
            saving_image();
            break;
        case '4':
            loadImage();
            flip();
            saving_image();
            break;
        case '5':
            loadImage();
            rotate();
            saving_image();
            break;
        case '6':
            loadImage();
            darken_lighten();
            saving_image();
            break;
        case '7':
            loadImage();
            detect_edges();
            saving_image();
            break;
        case '8':
            loadImage();
            enlarge();
            saving_image();
            break;
        case '9':
            loadImage();
            shrink();
            saving_image();
            break;
        case 'a':
            loadImage();
            mirror();
            saving_image();
            break;
        case 'b':
            loadImage();
            shuffle();
            saving_image();
            break;
        case 'c':
            loadImage();
            blur();
            saving_image();
            break;
        case 'd':
            loadImage();
            crop();
            saving_image();
        case 'e':
            loadImage();
            skewHorizontally();
            saving_image();
        case 'f':
            loadImage();
            skewVertically();
            saving_image();
        case 'x':
            exit(0);
            break;
        default:
            cout << "wrong choice" << endl;
            menu();
            break;
    }
}

void black_white() {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (image[i][j] > 127) //More than Average Gray level,So it's White
                image[i][j] = 255;
            else
                image[i][j] = 0; //Less than Average Gray level,So it's Black
        }
    }
}

void invert() {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}

void merge() {
    cout<<"Please enter name of image file to merge with: "<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] = image[i][j] ;
        }
    }
    loadImage();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}

void flip() {
    char letter;
    cout<<"Flip (h)orizontally or (v)ertically ? "<<endl;
    cin>>letter;
    if(letter=='h')
    {
        /*To flip horizontally we must copy every pixel in the very right to the left
          Without affecting the photo So we will do this in a new array named after image2 */
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0,z=SIZE-1 ; j < SIZE && z >= 0 ; j++, z--)
            {
                image2[i][j] = image[i][z] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image2[i][j] ; //We will equalize them because it's the output
            }
        }
    }
    else if(letter=='v')
    {
        /*To flip vertically we must copy every pixel in the very down to the up
          Without affecting the photo So we will do this in a new array named after image2 */
        for (int i = 0,s=SIZE-1 ; i < SIZE && s >= 0 ; i++, s--)
        {
            for (int j = 0; j < SIZE ; j++)
            {
                image2[i][j] = image[s][j] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image2[i][j] ; //We will equalize them because it's the output
            }
        }
    }
}

void rotate() {
    int num;
    cout<<"Rotate (90),(180) or (270) degrees? "<<endl;
    cin>>num;
    if(num==90)
    {
        for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--) {
            for (int j = 0, z = SIZE - 1; j < SIZE && z >= 0; j++, z--) {
                image2[i][j] = image[z][i];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image2[i][j];
            }
        }
    }
    if(num==180)
    {
        for (int i = 0,s=SIZE-1 ; i < SIZE && s >= 0 ; i++, s--)
        {
            for (int j = 0,z=SIZE-1 ; j < SIZE && z >= 0 ; j++, z--)
            {
                image2[i][j] = image[s][z] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image2[i][j] ;
            }
        }
    }
    if(num==270)
    {
        for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--)
        {
            for (int j = 0, z = SIZE - 1; j < SIZE && z >= 0; j++, z--)
            {
                image2[i][j] = image[j][s];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image2[i][j];
            }
        }
    }
}

void darken_lighten() {
    int check;
    cout << "do u want darken-->1 or lighten-->2:";
    cin >> check;
    switch (check) {
        case 1: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image2[i][j] <= 60) {
                        image[i][j] = image2[i][j];
                    } else {
                        image[i][j] = image2[i][j] - 60;
                    }
                }
            }
            break;
        }


        case 2: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image2[i][j] >= 195) {
                        image[i][j] = image2[i][j];
                    }
                    else {
                        image[i][j] = image2[i][j] + 60;
                    }
                }
            }
            break;
        }

        default:
            darken_lighten();
            break;
    }
}

void detect_edges() {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] = image[i][j] ; //Equalize image2 to image
        }
    }
    int avg = 0;
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE ; j++)
        {
            avg += image[i][j];
        }
    }
    avg /= (256*256); //The average color per pixel
    for (int i = 0; i < SIZE; i++)
    {
        //The average will help us to detect whether the pixel is edge or not
        for (int j = 0; j < SIZE; j++)
        {
            //Here we are making sure that the pixel is edge and different from the rest neighbor pixels
            if( (image2[i][j] > avg && image2[i][j+1] < avg ) || (image2[i][j] < avg && image2[i][j+1] > avg )
                || (image2[i][j] > avg && image2[i-1][j] < avg) || (image2[i][j] < avg && image2[i-1][j] > avg)
                || (image2[i][j] > avg && image2[i+1][j+1] < avg) || (image2[i][j] < avg && image2[i+1][j+1] > avg) )
            {
                image[i][j] = 0; //Converting this edge pixel to Black
            }
            else
            {
                image[i][j] = 255; //Converting the non-edge pixels to White
            }
        }
    }
}

void enlarge() {
    int quarter;
    cout << "please enter the quarter u want to enlarge:";
    cin >> quarter;
    for (int i = 0; i < SIZE; i += 2) {
        for (int j = 0; j < SIZE; j += 2) {
            if (quarter == 1) {
                image2[i][j + 1] = image[i / 2][j / 2];
                image2[i + 1][j] = image[i / 2][j / 2];
                image2[i + 1][j + 1] = image[i / 2][j / 2];
            }
            else if (quarter == 2) {
                image2[i][j] = image[i / 2][(j + SIZE) / 2];
                image2[i][j + 1] = image[i / 2][(j + SIZE) / 2];
                image2[i + 1][j] = image[i / 2][(j + SIZE) / 2];
                image2[i + 1][j + 1] = image[i / 2][(j + SIZE) / 2];
            }
            else if (quarter == 3) {
                image2[i][j] = image[(i + SIZE) / 2][j / 2];
                image2[i][j + 1] = image[(i + SIZE) / 2][j / 2];
                image2[i + 1][j] = image[(i + SIZE) / 2][j / 2];
                image2[i + 1][j + 1] = image[(i + SIZE) / 2][j / 2];
            }
            else if (quarter == 4) {
                image2[i][j] = image[(i + SIZE) / 2][(j + SIZE) / 2];
                image2[i][j + 1] = image[(i + SIZE) / 2][(j + SIZE) / 2];
                image2[i + 1][j] = image[(i + SIZE) / 2][(j + SIZE) / 2];
                image2[i + 1][j + 1] = image[(i + SIZE) / 2][(j + SIZE) / 2];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}

void shrink() {
    int choice;
    cout << "for 1/4 ->1\nfor 1/3 ->2\nfor 1/2 ->3\nenter:";
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < SIZE; i += 2)
        {
            for (int j = 0; j < SIZE; j += 2)
            {
                image2[i / 2][j / 2] = image[i][j];
            }

        }

    }
    else if (choice == 2)
    {
        for (int i = 0; i < SIZE; i += 3)
        {
            for (int j = 0; j < SIZE; j += 3)
            {
                image2[i / 3][j / 3] = image[i][j];
            }
        }
    }
    else if (choice == 3)
    {
        for (int i = 0; i < SIZE; i += 4)
        {
            for (int j = 0; j < SIZE; j += 4)
            {
                image2[i / 4][j / 4] = image[i][j];
            }
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image2[i][j];
        }
    }

}

void mirror() {
    char letter;
    cout << "Mirror (l)eft , (r)ight , (u)pper or (d)own side ?" << endl;
    cin >> letter;
    if (letter == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j]; //Equalize image2 to image
            }
        }
        //We want to mirror the left side ,So we will make the right side the same to the left
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0, z = SIZE - 1; j < z; j++, z--) {
                image[i][z] = image2[i][j];
            }
        }
    } else if (letter == 'r') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j]; //Equalize image2 to image
            }
        }
        //We want to mirror the right side ,So we will make the left side the same to the right
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE - 1, z = 0; j > z; j--, z++) {
                image[i][z] = image2[i][j];
            }
        }
    } else if (letter == 'u') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j]; //Equalize image2 to image
            }
        }
        //We want to mirror the upper side ,So we will make the lower side the same to the upper
        for (int i = 0, z = SIZE - 1; i < z; i++, z--) {
            for (int j = 0; j < SIZE; j++) {
                image[z][j] = image2[i][j];
            }
        }
    } else if (letter == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j]; //Equalize image2 to image
            }
        }
        //We want to mirror the lower side ,So we make the upper side the same to the lower
        for (int i = SIZE - 1, z = 0; i > z; i--, z++) {
            for (int j = 0; j < SIZE; j++) {
                image[z][j] = image2[i][j];
            }
        }
    }
}


void shuffle() {
    int index = 0;
    string order;
    cout << "enter the order";
    cin >> order;
    while (index < 4) {
        if (index == 0) {
            if (order[index] == '1') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j] = image[i][j];
                    }
                }

            }
            else if (order[index] == '2') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j] = image[i][j + SIZE / 2];
                    }
                }
            }
            else if (order[index] == '3') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j] = image[i + SIZE / 2][j];
                    }

                }
            }
            else if (order[index] == '4') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j] = image[i + SIZE / 2][j + SIZE / 2];
                    }

                }
            }
        }
            // --------------------
        else if (index == 1) {
            if (order[index] == '1') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j + SIZE / 2] = image[i][j];
                    }

                }

            }
            else if (order[index] == '2') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j + SIZE / 2] = image[i][j + SIZE / 2];
                    }

                }
            }
            else if (order[index] == '3') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j + SIZE / 2] = image[i + SIZE / 2][j];
                    }

                }
            }
            else if (order[index] == '4') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i][j + SIZE / 2] = image[i + SIZE / 2][j + SIZE / 2];
                    }

                }
            }
        }
            // -------------
        else if (index == 2) {
            if (order[index] == '1') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j] = image[i][j];
                    }

                }

            }
            else if (order[index] == '2') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j] = image[i][j + SIZE / 2];
                    }

                }
            }
            else if (order[index] == '3') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j] = image[i + SIZE / 2][j];
                    }

                }
            }
            else if (order[index] == '4') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j] = image[i + SIZE / 2][j + SIZE / 2];
                    }

                }
            }
        }// ---------
        else if (index == 3) {
            if (order[index] == '1') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j + SIZE / 2] = image[i][j];
                    }

                }
            }
            else if (order[index] == '2') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j + SIZE / 2] = image[i][j + SIZE / 2];
                    }

                }
            }
            else if (order[index] == '3') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j + SIZE / 2] = image[i + SIZE / 2][j];
                    }

                }
            }
            else if (order[index] == '4') {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        image2[i + SIZE / 2][j + SIZE / 2] = image[i + SIZE / 2][j + SIZE / 2];
                    }

                }
            }
        }
        index++;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}

void blur() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i + 1][j + 1] = (image[i][j] + image[i][j + 1] + image[i][j + 2] + image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j + 2] + image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2]) / 9;
        }
    }
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++){
            image[i][j]=image2[i][j];
        }
    }
}

void crop(){
    int x,y,l,w;
    cout<<"Please enter x : ";
    cin>>x;
    cout<<"Please enter y : ";
    cin>>y;
    cout<<"Please enter Length : ";
    cin>>l;
    cout<<"Please enter Width : ";
    cin>>w;
    for(int i=0 ; i < SIZE ;i++ )
    {
        for(int j=0; j < SIZE ;j++ )
        {
            if(i<y || i>(y+l) ) //This is the vertical region that does not contain the photo
            {
                image[i][j]=255;
            }
            if(j<x || j>(x+w) )//This is the horizontal region that does not contain the photo
            {
                image[i][j]=255;
            }
        }
    }
}

void skewHorizontally(){//Skew right

    double rad,move,step;
    int x;
    cout<<"Please enter the angle :";
    cin>>rad;
    rad=(rad*22)/(180/7);
    x=256/(1+(1/tan(rad)));
    step=256-x;
    move=step/256;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = 255;
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image2[(i*x)/SIZE][j]=image[i][j];
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        {
            image3[i+(int)step][j]=image2[i][j];
        }
        step-=move;
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=image3[i][j];
        }
    }

}


void skewVertically(){

    double rad,move,step;
    int x;
    cout<<"Please enter the angle :";
    cin>>rad;
    rad=(rad*22)/(180/7);
    x=256/(1+(1/tan(rad)));
    step=256-x;
    move=step/256;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = 255;
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image2[(i*x)/SIZE][j]=image[i][j];
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        {
            image3[i+(int)step][j]=image2[i][j];
        }
        step-=move;
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=image3[i][j];
        }
    }

}



/*void grain()
{
    for (int i = 0; i < SIZE; i += 2)
    {
        for (int j = 0; j < SIZE; j += 2)
        {
            image2[i / 1][j / 1] = image[i][j];
        }
    }



    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image2[i][j];
        }
    }
}*/
