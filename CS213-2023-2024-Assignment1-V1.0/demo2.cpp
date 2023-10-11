//FCAI - OOP programing - 2023 - Assignment 1
// Program: demo2.cpp
// Author1 and ID : Mazen Abdelfattah - 20230607
// Author2 and ID : Malak Khattab - 20210403
// Author3 and ID : Gehad Shaban - 20220535
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();
void darken_lighten() {
    int check;
    cout << "do u want darken-->1 or lighten-->2:";
    cin >> check;
    switch (check)
    {
        case 1: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image[i][j] <= 60) {
                        image2[i][j] = image[i][j];
                    }
                    else {
                        image2[i][j] = image[i][j] - 60;
                    }
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image[i][j] >= 195) {
                        image2[i][j] = image[i][j];
                    }
                    else {
                        image2[i][j] = image[i][j] + 60;
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

int main()
{
  loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void doSomethingForImage()
{
    char choice;
    cout<<"Please select a filter to apply or 0 to exit"<<endl;
    cout<<"1-Black & White Filter"<<endl;
    cout<<"2-Invert Filter"<<endl;
    cout<<"3-Merge Filter"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Rotate Image"<<endl;
    cout<<"6-Darken and Lighten Image"<<endl;
    cout<<"7-Detect Image Edges"<<endl;
    cout<<"8-Enlarge Image"<<endl;
    cout<<"9-Shrink Image"<<endl;
    cout<<"a-Mirror 1/2 Image"<<endl;
    cout<<"b-Shuffle Image"<<endl;
    cout<<"c-Blur Image"<<endl;
    cout<<"d-Crop Image"<<endl;
    cout<<"e-Skew Image Right"<<endl;
    cout<<"f-Skew Image Up"<<endl;
    cout<<"s- Save the image to a file"<<endl; //I have no idea how to code this
    cout<<"0-Exit"<<endl; //I have no idea how to code this
    cin>>choice;
    if(choice=='1')
    {
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
        //The gray level is 127 (255/2)
        //White 255
        //Black 0
    }
    else if(choice=='2')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = 255 - image[i][j];
            }
        }
    }
    else if(choice=='3')
    {
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
    else if(choice=='4')
    {
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
    else if(choice=='5')
    {
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
    else if(choice=='6'){
        int check;
        cout << "do u want darken-->1 or lighten-->2: ";
        cin >> check;
        if(check==1)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image2[i][j] <= 60) {
                        image[i][j] = image2[i][j];
                    }
                    else {
                        image[i][j] = image2[i][j] - 60;
                    }
                }
            }
        }
        else if(check==2)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (image[i][j] >= 195) {
                        image[i][j] = image[i][j];
                    }
                    else {
                        image[i][j] = image2[i][j] + 60;
                    }
                }
            }
        }
    }
    else if(choice=='7')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[i][j] ; //Egualize image2 to image
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
    else if(choice=='8'){}
    else if(choice=='9'){}
    else if(choice=='a')
    {
        char letter;
        cout<<"Mirror (l)eft , (r)ight , (u)pper or (d)own side ?"<<endl;
        cin>>letter;
        if(letter=='l')
        {
            for (int i = 0; i < SIZE ; i++)
            {
                for (int j = 0; j < SIZE ; j++)
                {
                    image2[i][j] = image[i][j]; //Equalize image2 to image
                }
            }
            //We want to mirror the left side ,So we will make the right side the same to the left
            for (int i = 0; i < SIZE ; i++ )
            {
                for (int j = 0, z = SIZE - 1; j < z ; j++, z--)
                {
                    image[i][z]=image2[i][j];
                }
            }
        }
        else if(letter=='r')
        {
            for (int i = 0; i < SIZE ; i++)
            {
                for (int j = 0; j < SIZE ; j++)
                {
                    image2[i][j] = image[i][j]; //Equalize image2 to image
                }
            }
            //We want to mirror the right side ,So we will make the left side the same to the right
            for (int i = 0; i < SIZE ; i++ )
            {
                for (int j = SIZE - 1, z = 0 ; j > z ; j--, z++)
                {
                    image[i][z]=image2[i][j];
                }
            }
        }
        else if(letter=='u')
        {
            for (int i = 0; i < SIZE ; i++)
            {
                for (int j = 0; j < SIZE ; j++)
                {
                    image2[i][j] = image[i][j]; //Equalize image2 to image
                }
            }
            //We want to mirror the upper side ,So we will make the lower side the same to the upper
            for (int i = 0 , z = SIZE - 1 ; i < z ; i++ ,z-- )
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    image[z][j]=image2[i][j];
                }
            }
        }
        else if(letter=='d')
        {
            for (int i = 0; i < SIZE ; i++)
            {
                for (int j = 0; j < SIZE ; j++)
                {
                    image2[i][j] = image[i][j]; //Equalize image2 to image
                }
            }
            //We want to mirror the lower side ,So we make the upper side the same to the lower
            for (int i = SIZE - 1 , z = 0 ; i >z  ; i-- ,z++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    image[z][j]=image2[i][j];
                }
            }
        }
    }
    else if(choice=='b'){}
    else if(choice=='c'){}
    else if(choice=='d')
    {
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
    else if(choice=='e'){}
    else if(choice=='f'){}
    else
    {
        return ;
    }


}
