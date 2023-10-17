//FCAI - OOP programing - 2023 - Assignment 1
// Program: demo2.cpp
// Author1 and ID : Mazen Abdelfattah - 20230607
// Author2 and ID : Malak Khattab - 20210403
// Author3 and ID : Gehad Shaban - 20220535
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a RGBImage and store in another file

#include<iostream>
#include<cstring>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;


unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];

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
    readRGBBMP(imageFileName, image);
}

void saving_image() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);

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
       /* case '9':
            loadImage();
            shrink();
            saving_image();
            break;*/
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
            /*case 'c':
                loadImage();
                blur();
                saving_image();
                break;*/
        case'd':
            loadImage();
            crop();
            saving_image();
            break;
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
            for(int k =0 ; k < RGB ; k ++) {
                if (image[i][j][k] > 127) //More than Average Gray level,So it's White
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0; //Less than Average Gray level,So it's Black
            }
        }
    }
}

void invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                { image[i][j][k] = 255 - image[i][j][k]; }
            }
        }
    }
}
void merge() {
    cout<<"Please enter name of image file to merge with: "<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k= 0; k < RGB; k ++)
            {
                image2[i][j][k] = image[i][j][k] ;}
        }
    }
    loadImage();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k= 0; k < RGB; k ++)
            {image[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;}
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
        for (int k = 0; k <RGB; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0,z=SIZE-1 ; j < SIZE && z >= 0 ; j++, z--)
                {image2[i][j][k] = image[i][z][k] ;}
            }
        }
        for (int k =0; k <RGB; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {image[i][j][k] = image2[i][j][k] ;}
                    //We will equalize them because it's the output

        }
        }
    }
    else if(letter=='v')
    {
        /*To flip vertically we must copy every pixel in the very down to the up
          Without affecting the photo So we will do this in a new array named after image2 */
        for (int k = 0; k <RGB; k++)
        {
            for (int i = 0,s=SIZE-1 ; i < SIZE && s >= 0 ; i++, s--)
            {
                for (int j = 0; j < SIZE ; j++)
                {image2[i][j][k] = image[s][j][k] ;}
            }
        }
        for (int k = 0; k <RGB; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {image[i][j][k] = image2[i][j][k] ;}
                //We will equalize them because it's the output
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
        for(int k =0; k <RGB; k++){
            for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--)
            {
                for (int j = 0, z = SIZE - 1; j < SIZE && z >= 0; j++, z--)
                {image2[i][j][k] = image[z][i][k];}
            }
        }
        for (int k =0; k <RGB; k ++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {image[i][j][k] = image2[i][j][k];}
            }
        }
    }
    if(num==180)
    {
        for (int k =0;k <RGB; k++ )
        {
            for (int i = 0,s=SIZE-1 ; i < SIZE && s >= 0 ; i++, s--)
            {
                for (int j = 0,z=SIZE-1 ; j < SIZE && z >= 0 ; j++, z--)
                {image2[i][j][k] = image[s][z][k] ;}
            }
        }
        for (int k =0;k < RGB; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {image[i][j][k]= image2[i][j][k] ;}
            }
        }
    }
    if(num==270)
    {
        for (int k =0;k < RGB; k++)
        {
            for (int i = 0, s = SIZE - 1; i < SIZE && s >= 0; i++, s--)
            {
                for (int j = 0, z = SIZE - 1; j < SIZE && z >= 0; j++, z--)
                {image2[i][j][k] = image[j][s][k];}
            }
        }
        for (int k =0;k < RGB; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {image[i][j][k] = image2[i][j][k];}
            }
        }
    }
}
void darken_lighten() {
    int check;
    cout << "do u want darken-->1 or lighten-->2:";
    cin >> check;
    for (int k = 0; k < RGB; ++k) {
        switch (check) {
            case 1: {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j][k] = image[i][j][k];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        if (image2[i][j][k] <= 60) {
                            image[i][j][k] = image2[i][j][k];
                        } else {
                            image[i][j][k] = image2[i][j][k] - 60;
                        }
                    }
                }
                break;
            }


            case 2: {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j][k] = image[i][j][k];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        if (image2[i][j][k] >= 195) {
                            image[i][j][k] = image2[i][j][k];
                        } else {
                            image[i][j][k] = image2[i][j][k] + 60;
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
}

void detect_edges() {
    //1- convert greyscale to black and white
    for (int k = 0; k < RGB; k++)
    {
        for (int i = 1; i < SIZE - 1; i++)
        {
            for (int j = 1; j < SIZE - 1; j++)
            {
                //convert to black and white
                if (image[i][j][k] > 127)
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0;
            }
        }
    }
    for (int k = 0; k < RGB; k++) {
        for (int i = 1; i < SIZE - 1; i += 1)
        {
            for (int j = 1; j < SIZE - 1; j += 1)
            {
                //2- check detection of current pixel against before/after pixels
                if (image[i][j][k] == image[i][j + 1][k] and image[i][j][k] == image[i][j - 1][k])
                    //set value to white
                    image2[i][j][k] = 255;
                else
                    //set value to black
                    image2[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) { image[i][j][k] = image2[i][j][k]; }
        }
    }
}
void enlarge() {
    int quarter;
    cout << "please enter the quarter u want to enlarge:";
    cin >> quarter;
    for (int k = 0; k < RGB; k++){
        for (int i = 0; i < SIZE; i += 2)
        {
            for (int j = 0; j < SIZE; j += 2)
            {
                if (quarter == 1) {
                image2[i][j + 1][k] = image[i / 2][j / 2][k];
                image2[i + 1][j][k] = image[i / 2][j / 2][k];
                image2[i + 1][j + 1][k] = image[i / 2][j / 2][k];
                }
                else if (quarter == 2) {
                image2[i][j][k] = image[i / 2][(j + SIZE) / 2][k];
                image2[i][j + 1][k] = image[i / 2][(j + SIZE) / 2][k];
                image2[i + 1][j][k] = image[i / 2][(j + SIZE) / 2][k];
                image2[i + 1][j + 1][k] = image[i / 2][(j + SIZE) / 2][k];
                }
                else if (quarter == 3) {
                image2[i][j][k] = image[(i + SIZE) / 2][j / 2][k];
                image2[i][j + 1][k] = image[(i + SIZE) / 2][j / 2][k];
                image2[i + 1][j][k] = image[(i + SIZE) / 2][j / 2][k];
                image2[i + 1][j + 1][k] = image[(i + SIZE) / 2][j / 2][k];
                }
                else if (quarter == 4) {
                image2[i][j][k] = image[(i + SIZE) / 2][(j + SIZE) / 2][k];
                image2[i][j + 1][k] = image[(i + SIZE) / 2][(j + SIZE) / 2][k];
                image2[i + 1][j][k] = image[(i + SIZE) / 2][(j + SIZE) / 2][k];
                image2[i + 1][j + 1][k] = image[(i + SIZE) / 2][(j + SIZE) / 2][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) { image[i][j][k] = image2[i][j][k]; }
        }
    }
}
void mirror() {
    char letter;
    cout << "Mirror (l)eft , (r)ight , (u)pper or (d)own side ?" << endl;
    cin >> letter;
    if (letter == 'l') {
        for (int k =0; k < RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                {image2[i][j][k] = image[i][j][k];} //Equalize image2 to image
            }
        }
        //We want to mirror the left side ,So we will make the right side the same to the left
        for (int k =0; k < RGB ; k ++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, z = SIZE - 1; j < z; j++, z--)
                {image[i][z][k] = image2[i][j][k];}
            }
        }
    }
    else if (letter == 'r') {
        for (int k =0; k < RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                {image2[i][j][k] = image[i][j][k];} //Equalize image2 to image
            }

        }
        //We want to mirror the right side ,So we will make the left side the same to the right
        for (int k =0; k < RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE - 1, z = 0; j > z; j--, z++)
                {image[i][z][k] = image2[i][j][k];}
            }
        }
    }
    else if (letter == 'u') {
        for (int k =0; k < RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                {image2[i][j][k] = image[i][j][k];} //Equalize image2 to image
            }
        }
        //We want to mirror the upper side ,So we will make the lower side the same to the upper
        for (int k =0; k < RGB; k++){
            for (int i = 0, z = SIZE - 1; i < z; i++, z--) {
                for (int j = 0; j < SIZE; j++)
                {image[z][j][k] = image2[i][j][k];}
            }
        }
    }
    else if (letter == 'd') {
        for (int k =0; k < RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                {image2[i][j][k] = image[i][j][k];} //Equalize image2 to image
            }
        }
        //We want to mirror the lower side ,So we make the upper side the same to the lower
        for (int k =0; k < RGB; k++){
            for (int i = SIZE - 1, z = 0; i > z; i--, z++) {
                for (int j = 0; j < SIZE; j++)
                {image[z][j][k] = image2[i][j][k];}
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
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j][k] = image[i][j][k];}
                    }
                }

            }
            else if (order[index] == '2') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j][k] = image[i][j + SIZE / 2][k];}
                    }
                }
            }
            else if (order[index] == '3') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j][k] = image[i + SIZE / 2][j][k];}
                    }
                }
            }
            else if (order[index] == '4') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j][k] = image[i + SIZE / 2][j + SIZE / 2][k];}
                    }
                }
            }
        }
            // --------------------
        else if (index == 1) {
            if (order[index] == '1') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j + SIZE / 2][k] = image[i][j][k];}
                    }
                }

            }
            else if (order[index] == '2') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j + SIZE / 2][k] = image[i][j + SIZE / 2][k];}
                    }
                }
            }
            else if (order[index] == '3') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j + SIZE / 2] [k]= image[i + SIZE / 2][j][k];}
                    }
                }
            }
            else if (order[index] == '4') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i][j + SIZE / 2] [k]= image[i + SIZE / 2][j + SIZE / 2][k];}
                    }
                }
            }
        }
            // -------------
        else if (index == 2) {
            if (order[index] == '1') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j][k] = image[i][j][k];}
                    }
                }

            }
            else if (order[index] == '2') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j][k] = image[i][j + SIZE / 2][k];}
                    }
                }
            }
            else if (order[index] == '3') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j][k] = image[i + SIZE / 2][j][k];}
                    }
                }
            }
            else if (order[index] == '4') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j][k]= image[i + SIZE / 2][j + SIZE / 2][k];}
                    }
                }
            }
        }// ---------
        else if (index == 3) {
            if (order[index] == '1') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j + SIZE / 2][k] = image[i][j][k];}
                    }
                }
            }
            else if (order[index] == '2') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j + SIZE / 2] [k]= image[i][j + SIZE / 2][k];}
                    }
                }
            }
            else if (order[index] == '3') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j + SIZE / 2][k] = image[i + SIZE / 2][j][k];}
                    }
                }
            }
            else if (order[index] == '4') {
                for (int k=0; k < RGB; k++){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = 0; j < SIZE / 2; j++)
                        {image2[i + SIZE / 2][j + SIZE / 2] [k]= image[i + SIZE / 2][j + SIZE / 2][k];}
                    }
                }
            }
        }
        index++;
    }
    for (int k=0; k < RGB; k++){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
            {image[i][j][k] = image2[i][j][k];}
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
                for (int k =0; k < RGB ; k++) {
                    if (i < y || i > (y + l)) //This is the vertical region that does not contain the photo
                    { image[i][j][k] = 255; }
                    if (j < x || j > (x + w))//This is the horizontal region that does not contain the photo
                    { image[i][j][k] = 255; }
                }
            }
        }
}
