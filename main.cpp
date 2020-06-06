#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int width = 500;
int height = 500;
int pointSize = 5;
int lineSize = 1.0;
string file = "";
string chart = "";
vector<float> data;
vector<float> xVals;
vector<float> yVals;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(pointSize);
    glLineWidth(lineSize);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void extractFile(string file) {
    ifstream obj;
    obj.open(file.c_str());
    if(!obj.is_open()) {
        cout << "Error! Couldn't open file. Exiting." << endl;
        exit(-1);
    }
    else {
        cout << "File successfully opened" << endl;
        if(obj.good()) {
            int currentNumber = 0;
            while(obj >> currentNumber) {
                data.push_back(currentNumber);
            }
            obj.close();
        }
    }
}

void collectValues() {
    for(unsigned int i = 0; i < data.size(); i++) {
        if(i % 2 == 0) {
            xVals.push_back(data[i]);
        }
        else {
            yVals.push_back(data[i]);
        }
    }
}

void verifyChart() {
    if(chart == "column" | chart == "point" | chart == "line" | chart == "area") {
        cout << "Chart name accepted" << endl;
    }
    else {
        cout << "Error! Incorrect input. Exiting." << endl;
        exit(-1);
    }
}

void printX() {
    cout << "The X Values are: ";
    for(unsigned int z = 0; z < xVals.size(); z++) {
        cout << xVals[z] << " ";
    }
    cout << endl;
}

void printY() {
    cout << "The Y Values are: ";
    for(unsigned int g = 0; g < yVals.size(); g++) {
        cout << yVals[g] << " ";
    }
    cout << endl;
}

void draw_point() {
    glPointSize(5.0);
    cout << "set_color 1.0 1.0 1.0" << endl;
    glBegin(GL_POINTS);
        for(int i = 0; i < xVals.size(); i++) {
            glVertex2f(xVals[i] * 5 + 50, yVals[i] * 5 + 50);
            cout << "draw_point " << pointSize << " " << xVals[i] << " " << yVals[i] << endl;
        }
    glEnd();
}

void draw_line() {
    cout << "set_color 1.0 1.0 1.0" << endl;
    glBegin(GL_LINES);
        int temp = 1;
        for(int i = 0; i < xVals.size(); i++) {
            glVertex2f(xVals[i] * 5 + 50, yVals[i] * 5 + 50);
            if(temp != xVals.size()) {
                glVertex2f(xVals[i + 1] * 5 + 50, yVals[i + 1] * 5 + 50);
            }
            else {
                glVertex2f(xVals[i] * 5 + 50, yVals[i] * 5 + 50);
            }
            cout << "draw_line" << " " << lineSize << " " << xVals[i] << " " << yVals[i] << " " << xVals[i+1] <<  " " << yVals[i+1] << endl;
            temp++;
        }
    glEnd();
}

string getFilename() {
    string filename = "";
    cout << "Enter the name of your data file: ";
    cin >> filename;
    return filename;
}

string getChartname() {
    string chartname = "";
    cout << "What kind of chart do you want to create? ";
    cin >> chartname;
    return chartname;
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    // Graph lines and tick marks
    glBegin(GL_LINES);
        glVertex2f(40.0, 50.0);     // X Axis
        glVertex2f(460.0, 50.0);
        glVertex2f(50.0, 40.0);     // Y Axis
        glVertex2f(50.0, 460.0);
        glVertex2f(40.0, 90.0);     // Horizontal Lines
        glVertex2f(460.0, 90.0);
        glVertex2f(40.0, 130.0);
        glVertex2f(460.0, 130.0);
        glVertex2f(40.0, 170.0);
        glVertex2f(460.0, 170.0);
        glVertex2f(40.0, 210.0);
        glVertex2f(460.0, 210.0);
        glVertex2f(40.0, 250.0);
        glVertex2f(460.0, 250.0);
        glVertex2f(40.0, 290.0);
        glVertex2f(460.0, 290.0);
        glVertex2f(40.0, 330.0);
        glVertex2f(460.0, 330.0);
        glVertex2f(40.0, 370.0);
        glVertex2f(460.0, 370.0);
        glVertex2f(40.0, 410.0);
        glVertex2f(460.0, 410.0);
        glVertex2f(40.0, 450.0);
        glVertex2f(460.0, 450.0);
        glVertex2f(90.0, 40.0);     // Vertical Marks
        glVertex2f(90.0, 50.0);
        glVertex2f(130.0, 40.0);
        glVertex2f(130.0, 50.0);
        glVertex2f(170.0, 40.0);
        glVertex2f(170.0, 50.0);
        glVertex2f(210.0, 40.0);
        glVertex2f(210.0, 50.0);
        glVertex2f(250.0, 40.0);
        glVertex2f(250.0, 50.0);
        glVertex2f(290.0, 40.0);
        glVertex2f(290.0, 50.0);
        glVertex2f(330.0, 40.0);
        glVertex2f(330.0, 50.0);
        glVertex2f(370.0, 40.0);
        glVertex2f(370.0, 50.0);
        glVertex2f(410.0, 40.0);
        glVertex2f(410.0, 50.0);
        glVertex2f(450.0, 40.0);
        glVertex2f(450.0, 50.0);
    glEnd();

    if(chart == "point") {
        draw_point();
    }
    else if(chart == "line") {
        draw_point();
        draw_line();
    }

    glFlush();
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
    // Collect file information
    file = getFilename();

    // Open file and save contents to main vector
    extractFile(file);

    // Collect chart information
    chart = getChartname();

    // Verify chart
    verifyChart();

    // Pair x and y values for GLUT window
    collectValues();

    // Output X and Y Values
    printX();
    printY();

    // Calculate to scale data to the size of the output window

    // Output a sequence of graphics commands to create chart

    // GLUT application
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Computer Graphics Homework #1");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}

