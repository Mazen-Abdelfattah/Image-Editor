// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

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
    int choice;
    cout<<"Please select a filter to apply or 0 to exit"<<endl;
    cout<<"1-Black & White Filter"<<endl;
    cout<<"2-Invert Filter"<<endl;
    cout<<"3-Merge Filter"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Rotate Image"<<endl;
    cout<<"6-Darken and Lighten Image"<<endl;
    cout<<"7-Detect Image Edges"<<endl;
 /*    cout<<"8-Enlarge Image"<<endl;
    cout<<"9-Shrink Image"<<endl;
    cout<<"a-Mirror 1/2 Image"<<endl;
    cout<<"b-Shuffle Image"<<endl;
    cout<<"c-Blur Image"<<endl;
    cout<<"d-Crop Image"<<endl;
    cout<<"e-Skew Image Right"<<endl;
    cout<<"f-Skew Image Up"<<endl;
    cout<<"s-Save the image to a file"<<endl;*/
    cout<<"0-Exit"<<endl;
    cin>>choice;
    if(choice==1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                if (image[i][j] > 127)
                    image[i][j] = 255;
                else
                    image[i][j] = 0;
            }
        }
    }
    else if(choice==2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = 255 - image[i][j];
            }
        }
    }
    else if(choice==3)
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
    else if(choice==4)
    {
        char letter;
        cout<<"Flip (h)orizontally or (v)ertically ? "<<endl;
        cin>>letter;
        if(letter=='h')
        {
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
                    image[i][j] = image2[i][j] ;
                }
            }
        }
        else if(letter=='v')
        {
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
                    image[i][j] = image2[i][j] ;
                }
            }
        }
    }
    else if(choice==5)
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
    else if(choice==6)
    {
        for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--)
        {
            for (int j = 0, z = SIZE - 1; j < SIZE && z >= 0; j++, z--)
            {
                image2[i][j] = image[z][i];
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
    else if(choice==7)
    {
        for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--)
        {
            for (int j = 0, z = j + 1; j < SIZE && z < SIZE ; j++, z++)
            {
                if(image[i][j]==image[i][z])
                {
                    image[i][j] = 0;
                    j++;
                }
                else
                {
                    image[i][z] = 255;
                }
            }
        }
    }


}
