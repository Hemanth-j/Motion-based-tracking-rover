//Motion based tracking rover
// install the dependencies library AFMotor and NewPing library
//Created by students of Reva University (cse)



#include<NewPing.h>
#include<Servo.h>
#include<AFMotor.h>
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

Servo myservo;
 
int pos =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myservo.attach(10);
{
for(pos = 90; pos <= 180; pos += 1){
  myservo.write(pos);
  delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
  myservo.write(pos);
  delay(15);
}for(pos = 0; pos<=90; pos += 1) {
  myservo.write(pos);
  delay(15);
}
}
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);

}

void loop() {

  delay(50);
 unsigned int distance = sonar.ping_cm();
Serial.print("distance");
Serial.println(distance);


int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);

Serial.print("RIGHT");
Serial.println(Right_Value);
Serial.print("LEFT");
Serial.println(Left_Value);

if((Right_Value==1) && (distance>=10 && distance<=30)&&(Left_Value==1)){
  Motor1.setSpeed(120);
  Motor1.run(FORWARD);
  Motor2.setSpeed(120);
  Motor2.run(FORWARD);
  Motor3.setSpeed(120);
  Motor3.run(FORWARD);
  Motor4.setSpeed(120);
  Motor4.run(FORWARD);
}else if((Right_Value==0) && (Left_Value==1)) {
  Motor1.setSpeed(200);
  Motor1.run(FORWARD);
  Motor2.setSpeed(200);
  Motor2.run(FORWARD);
  Motor3.setSpeed(100);
  Motor3.run(BACKWARD);
  Motor4.setSpeed(100);
  Motor4.run(BACKWARD);
}else if((Right_Value==1)&&(Left_Value==0)) {
  Motor1.setSpeed(100);
  Motor1.run(BACKWARD);
  Motor2.setSpeed(100);
  Motor2.run(BACKWARD);
  Motor3.setSpeed(200);
  Motor3.run(FORWARD);
  Motor4.setSpeed(200);
  Motor4.run(FORWARD);
}else if((Right_Value==1)&&(Left_Value==1)) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
}else if(distance > 1 && distance < 10) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  }
 }


MAD LAB


# Motion-based-tracking-rover
Reva Hack

Mad lab

1>:  Program 1: Create an application to design a Visiting Card. The Visiting card should have a 
company logo at the top right corner. The company name should be displayed in Capital letters, 
aligned to the centre. Information like the name of the employee, job title, phone number, 
address, email, fax and the website address are to be displayed. Insert a horizontal line between 
the job title and the phone number


Activity_main.XML
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:background="#988D8D"
 tools:context=".MainActivity">
 <TextView
 android:id="@+id/textView4"
 android:layout_width="371dp"
 android:layout_height="wrap_content"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="28dp"
 android:layout_marginLeft="28dp"
 android:layout_marginEnd="12dp"
 android:layout_marginRight="12dp"
 android:layout_marginBottom="219dp"
 android:text="Address:REVA University, Kattigenahalli | Bangalore -
560 064"
 android:textAlignment="center"
 android:textColor="#DB2F2F"
 android:textSize="24sp" />
 <TextView
 android:id="@+id/textView5"
 android:layout_width="250dp"
 android:layout_height="wrap_content"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="87dp"
 android:layout_marginLeft="87dp"
 android:layout_marginEnd="73dp"
 android:layout_marginRight="73dp"
 android:layout_marginBottom="157dp"
 android:text="Ph No: 9876543210"
 android:textAlignment="center"
 android:textColor="#3F51B5"
 android:textSize="24sp" />
 <TextView 
 android:id="@+id/textView6"
 android:layout_width="367dp"
 android:layout_height="wrap_content"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="25dp"
 android:layout_marginLeft="25dp"
 android:layout_marginEnd="19dp"
 android:layout_marginRight="19dp"
 android:layout_marginBottom="64dp"
 android:text="Email Id: soujanya.bk@reva.edu.in"
 android:textAlignment="center"
 android:textColor="@color/purple_500"
 android:textSize="24sp" />
 <TextView
 android:id="@+id/textView3"
 android:layout_width="367dp"
 android:layout_height="66dp"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="32dp"
 android:layout_marginLeft="32dp"
 android:layout_marginEnd="12dp"
 android:layout_marginRight="12dp"
 android:layout_marginBottom="287dp"
 android:text="Assistant Professor-CSE"
 android:textAlignment="center"
 android:textColor="@color/purple_700"
 android:textSize="24sp" />
 <ImageView
 android:id="@+id/imageView3"
 android:layout_width="155dp"
 android:layout_height="98dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="12dp"
 android:layout_marginRight="12dp"
 android:layout_marginBottom="495dp"
 app:srcCompat="@drawable/reva" />
 <View
 android:id="@+id/view"
 android:layout_width="wrap_content"
 android:layout_height="4dp"
 android:layout_alignParentBottom="true"
 android:layout_marginBottom="487dp"
 android:background="#4444" />
 <TextView
 android:id="@+id/textView2"
 android:layout_width="176dp"
 android:layout_height="wrap_content"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="95dp"
 android:layout_marginLeft="95dp"
 android:layout_marginEnd="140dp"
 android:layout_marginRight="140dp"
 android:layout_marginBottom="401dp"
 android:text="Soujanya BK"
 android:textAlignment="center"
 android:textColor="@color/cardview_dark_background"
 android:textSize="24sp"
 android:textStyle="bold" />
 <TextView
 android:id="@+id/textView7"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="99dp"
 android:layout_marginRight="99dp"
 android:layout_marginBottom="495dp"
 android:layout_toStartOf="@+id/imageView3"
 android:layout_toLeftOf="@+id/imageView3"
 android:text="REVA University"
 android:textColor="#EB493D"
 android:textSize="25sp"
 android:textStyle="bold" />
 <Button
 android:id="@+id/button"
 android:layout_width="192dp"
 android:layout_height="wrap_content"
 android:text="Know more" />
</RelativeLayout>


MainActivity.Java


package com.example.program1;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
public class MainActivity extends AppCompatActivity {
Button button;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 button=findViewById(R.id.button);
 button.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Intent i=new Intent(Intent.ACTION_VIEW);
 i.setData(Uri.parse("https://www.reva.edu.in"));
 startActivity(i);
 }
 });
 }
}


2>: Program-2: Develop an Android application using controls like Button, TextView, EditText for 
designing a calculator having basic functionality like Addition, Subtraction, Multiplication, and 
Division


XML code:


<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <TextView
 android:layout_width="209dp"
 android:layout_height="60dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="108dp"
 android:layout_marginRight="108dp"
 android:layout_marginBottom="530dp"
 android:text="Simple Calci"
 android:textSize="36sp"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintLeft_toLeftOf="parent"
 app:layout_constraintRight_toRightOf="parent"
 app:layout_constraintTop_toTopOf="parent" />
 <EditText
 android:id="@+id/editText2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="115dp"
 android:layout_marginRight="115dp"
 android:layout_marginBottom="364dp"
 android:ems="10"
 android:hint="Enter the Number 2"
 android:inputType="textPersonName"
 android:text=""
 android:textColorHighlight="#FFFFFF" />
 <EditText
 android:id="@+id/editText1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="110dp"
 android:layout_marginRight="110dp"
 android:layout_marginBottom="439dp"
 android:ems="10"
 android:hint="Enter the Number 1"
 android:inputType="textPersonName"
 android:text=""
 android:textColorHighlight="#FFFFFF" />
 <Button
 android:id="@+id/button"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="260dp"
 android:layout_marginRight="260dp"
 android:layout_marginBottom="175dp"
 android:text="ADD"
 android:textStyle="bold"
 android:onClick="add"
 app:backgroundTint="#E8F381" />
 <Button
 android:id="@+id/button3"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="266dp"
 android:layout_marginRight="266dp"
 android:layout_marginBottom="61dp"
 android:text="MUL"
 android:onClick="mul"
 app:backgroundTint="#A1FAA4" />
 <Button
 android:id="@+id/button4"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="108dp"
 android:layout_marginRight="108dp"
 android:layout_marginBottom="63dp"
 android:text="DIV"
 android:onClick="div"
 app:backgroundTint="#E6C28C" />
 <Button
 android:id="@+id/button2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="105dp"
 android:layout_marginRight="105dp"
 android:layout_marginBottom="182dp"
 android:text="SUB"
 android:onClick="sub"
 app:backgroundTint="#ECA9A9" />
 <TextView
 android:id="@+id/tv1"
 android:layout_width="86dp"
 android:layout_height="61dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
android:layout_marginEnd="202dp"
 android:layout_marginRight="202dp"
 android:layout_marginBottom="274dp"
 android:text="0"
 android:textSize="36sp" />
</RelativeLayout>


Java code:


package com.example.program2;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
 EditText e1,e2;
 TextView tv;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 e1 =(EditText)findViewById(R.id.editText1);
 e2 = (EditText)findViewById(R.id.editText2);
 tv= (TextView)findViewById(R.id.tv1);
 }
 public void add(View v){
 int a1=Integer.parseInt(e1.getText().toString());
 int a2= Integer.parseInt(e2.getText().toString());
 int result=a1+a2;
 tv.setText(""+result);
 }
 public void sub(View v){
 int a1=Integer.parseInt(e1.getText().toString());
 int a2= Integer.parseInt(e2.getText().toString());
 int result=a1-a2;
 tv.setText(""+result);
 }
 public void mul(View v){
 int a1=Integer.parseInt(e1.getText().toString());
 int a2= Integer.parseInt(e2.getText().toString());
 int result=a1*a2;
 tv.setText(""+result);
 }
 public void div(View v){
 float a1=Integer.parseInt(e1.getText().toString());
 float a2= Integer.parseInt(e2.getText().toString());
 float result=a1/a2;
 tv.setText(""+result);
 }
}


3>: Program3: Create an android application to implement spinner class using java


Xml code:


<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:background="#8BC34A"
 android:backgroundTint="#8BC34A"
 android:contextClickable="true">
 <TextView
 android:id="@+id/txtVw"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_marginLeft="50dp"
 android:layout_marginTop="150dp"
 android:background="#3F51B5"
 android:text="Select Branch:"
 android:textColor="#FFEB3B"
 android:textSize="20sp"
 android:textStyle="bold" />
 <Spinner
 android:id="@+id/spinner1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignBottom="@+id/txtVw"
 android:layout_toRightOf="@+id/txtVw" />
</RelativeLayout>
Java code:
package com.example.program12;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity implements 
AdapterView.OnItemSelectedListener {
 String[] Branches = { "CSE", "AIDS", "IOT", "ECE", "CNIT" };
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 Spinner spin = (Spinner) findViewById(R.id.spinner1);
 ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, 
android.R.layout.simple_spinner_item, Branches);
 
adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_it
em);
spin.setAdapter(adapter);
 spin.setOnItemSelectedListener(this);
 }
 @Override
 public void onItemSelected(AdapterView<?> arg0, View arg1, int 
position,long id) {
 Toast.makeText(getApplicationContext(), "Selected User: 
"+Branches[position] ,Toast.LENGTH_SHORT).show();
 }
 @Override
 public void onNothingSelected(AdapterView<?> arg0) {
 // TODO - Custom Code
 }
}
  
  
5>: Program 5: Create an android application to demonstrate Scroll View 
  
XML Code:

  <RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <ScrollView
 android:layout_width="fill_parent"
 android:layout_height="fill_parent"
 android:background="#A88C83"
 android:scrollbars="vertical">
 <LinearLayout
 android:layout_width="fill_parent"
 android:layout_height="fill_parent"
 android:layout_margin="20dp"
 android:background="#4B3E3838"
 android:orientation="vertical">
 <Button
 android:id="@+id/cse"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:layout_gravity="center"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="100dp"
 android:backgroundTint="#FF5722"
 android:textStyle="bold"
 android:text="School of CSE"
 android:textColor="#fff"
 android:textSize="25sp" />
 <Button
 android:id="@+id/ece"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:layout_gravity="center"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="100dp"
 android:textStyle="bold"
 android:backgroundTint="#FF5722"
 android:text="SChool of ECE"
 android:textColor="#fff"
 android:textSize="25sp" />
 <Button
 android:id="@+id/eee"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:layout_gravity="center"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="100dp"
 android:backgroundTint="#FF5722"
android:text="School of EEE "
 android:textColor="#fff"
 android:textStyle="bold"
 android:textSize="25sp" />
 <Button
 android:id="@+id/mech"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:layout_gravity="center"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="100dp"
 android:backgroundTint="#FF5722"
 android:text="School of Mechanical"
 android:textColor="#fff"
 android:textStyle="bold"
 android:textSize="25sp" />
 <Button
 android:id="@+id/cnit"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:layout_gravity="center"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="100dp"
 android:backgroundTint="#FF5722"
 android:text="School of CNIT"
 android:textStyle="bold"
 android:textColor="#fff"
 android:textSize="25sp" />
 </LinearLayout>
 </ScrollView>
</RelativeLayout>
  
  
JAVA code:
  
  
package com.example.scrollapp;
import static com.example.scrollapp.R.*;
import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
Button cse;
Button ece;
Button mech;
Button eee;
Button cnit;
 @SuppressLint("MissingInflatedId")
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(layout.activity_main);
 cse=findViewById(id.cse);
 ece=findViewById(id.ece);
 cnit=findViewById(id.cnit);
 mech=findViewById(id.mech);
 eee=findViewById(id.eee);
 cse.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Toast.makeText(MainActivity.this, "welcome to cse", 
Toast.LENGTH_SHORT).show();
 Intent i=new Intent(Intent.ACTION_VIEW);
 
i.setData(Uri.parse("https://www.reva.edu.in/course/btech-in-computerscience-and-engineering"));
 startActivity(i);
 }
 });
 ece.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Toast.makeText(MainActivity.this, "welcome to ECE", 
Toast.LENGTH_SHORT).show();
 Intent i=new Intent(Intent.ACTION_VIEW);
 i.setData(Uri.parse("https://www.reva.edu.in/course/btechin-electronics-and-communication-engineering"));
 startActivity(i);
 }
 });
 mech.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Toast.makeText(MainActivity.this, "welcome to Mech", 
Toast.LENGTH_SHORT).show();
 Intent i=new Intent(Intent.ACTION_VIEW);
 i.setData(Uri.parse("https://www.reva.edu.in/course/btechin-mechanical-engineering"));
 startActivity(i);
 }
 });
eee.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Toast.makeText(MainActivity.this, "welcome to EEE", 
Toast.LENGTH_SHORT).show();
 Intent i = new Intent(Intent.ACTION_VIEW);
 i.setData(Uri.parse("https://www.reva.edu.in/course/btech-inelectrical-and-electronics-engineering"));
 startActivity(i);
}
});
 cnit.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View view) {
 Toast.makeText(MainActivity.this, "welcome to CNIT", 
Toast.LENGTH_SHORT).show();
 Intent i=new Intent(Intent.ACTION_VIEW);
 i.setData(Uri.parse("https://www.reva.edu.in/courselist/school-of-computing-and-information-technology"));
 startActivity(i);
 }
 });
 }
 }
  
8>: Program-8 : Write a program to create an activity with two buttons START and STOP. On pressing 
of the START button, the activity must start the counter by displaying the numbers from One and 
the counter must keep on counting until the STOP button is pressed. Display the counter value in a 
TextViewcontrol
  
  
Xml code:

  
  <?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <TextView
 android:id="@+id/textView1"
 android:layout_width="332dp"
 android:layout_height="wrap_content"
 android:layout_alignParentStart="true"
 android:layout_alignParentLeft="true"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginStart="41dp"
 android:layout_marginLeft="41dp"
 android:layout_marginEnd="38dp"
 android:layout_marginRight="38dp"
 android:layout_marginBottom="516dp"
 android:text="Counter Application"
 android:textSize="36sp"
 android:textStyle="bold" />
 <Button
 android:id="@+id/button1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="236dp"
 android:layout_marginRight="236dp"
 android:layout_marginBottom="89dp"
 android:text="Start"
 android:textSize="30sp"
 app:backgroundTint="#4CAF50" />
 <Button
 android:id="@+id/button2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="55dp"
 android:layout_marginRight="55dp"
 android:layout_marginBottom="92dp"
 android:text="STOP"
 android:textSize="30sp"
 app:backgroundTint="#EC5449" />
<TextView
 android:id="@+id/textView2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="165dp"
 android:layout_marginRight="165dp"
 android:layout_marginBottom="434dp"
 android:text="counter value"
 android:textSize="18sp"
 android:textStyle="bold" />
</RelativeLayout>
Java code:
package com.example.program5;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
 TextView txtCounter;
 Button btn_start,btn_stop;
 int count=0;
 Handler customHandler=new Handler();
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 txtCounter= (TextView)findViewById(R.id.textView2);
 btn_start =(Button)findViewById(R.id.button1);
 btn_stop=(Button)findViewById(R.id.button2);
 btn_start.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 customHandler.postDelayed(updateTimerThread,0);
 }
 });
 btn_stop.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 customHandler.removeCallbacks(updateTimerThread);
 }
 });
 }
 private final Runnable updateTimerThread =new Runnable() {
 @Override
 public void run() {
 txtCounter.setText(""+count);
 customHandler.postDelayed(this,1000);
 count++;
 }
 };
}

  
10>: Program-10: Develop a simple application with one EditText so that the user can write some text 
in it. Create a button called “Convert Text to Speech” that converts the user input text into voice
  
  
Xml code:

  
  <?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <TextView
 android:id="@+id/textView"
 android:layout_width="335dp"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="21dp"
 android:layout_marginBottom="486dp"
 android:text="Text2Speech"
 android:textSize="30sp" />
 <EditText
 android:id="@+id/editText"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="142dp"
 android:layout_marginBottom="377dp"
 android:ems="10"
 android:hint="Enter text here"
 android:inputType="textPersonName" />
 <Button
 android:id="@+id/convert"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="196dp"
 android:layout_marginBottom="236dp"
 android:onClick="convert"
 android:background="#6CEC71"
 android:text="CONVERT" />
</RelativeLayout>
  
  
Java code:

  
  package com.example.program7;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.view.View;
import android.widget.EditText;
import java.util.Locale;
public class MainActivity extends AppCompatActivity {
 EditText e1;
 TextToSpeech t1;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 e1=findViewById(R.id.editText);
 t1=new TextToSpeech(getApplicationContext(), new 
TextToSpeech.OnInitListener()
 {
 @Override
 public void onInit(int status) {
 if(status!=TextToSpeech.ERROR){
 t1.setLanguage(Locale.UK);
 }
 }
 });
 }
 public void convert(View V){
 String tospeak=e1.getText().toString();
 t1.speak(tospeak,TextToSpeech.QUEUE_FLUSH,null);
 }
}



