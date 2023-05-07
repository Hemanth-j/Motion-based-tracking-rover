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
  
               
4>: Program 4: Create an android application to Demonstrate the check box and radio button
Activity_Main.xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout
 xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <TextView
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Select the Year"
 android:textStyle="bold"
 android:layout_marginLeft="10dp"
 android:textSize="20sp"/>
 <!-- add RadioGroup which contain the many RadioButton-->
 <RadioGroup
 android:layout_marginTop="50dp"
 android:id="@+id/groupradio"
 android:layout_marginLeft="10dp"
 android:layout_width="fill_parent"
 android:layout_height="wrap_content">
 <!-- In RadioGroup create the 1 Radio Button-->
 <!-- like this we will add some more Radio Button-->
 <RadioButton
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:id="@+id/radia_id1"
 android:text="First year"
 android:textSize="20sp"/>
 <RadioButton
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:id="@+id/radia_id2"
 android:text="Second Year"
 android:textSize="20sp"/>
 <RadioButton
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:id="@+id/radia_id3"
 android:text="Third year"
 android:textSize="20sp"/>
 <RadioButton
 android:layout_width="fill_parent"
 android:layout_height="wrap_content"
 android:id="@+id/radia_id4"
 android:text="Fourth year"
android:textSize="20sp"/>
 </RadioGroup>
 <!-- add button For Submit the Selected item-->
 <Button
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Submit"
 android:id="@+id/submit"
 android:textStyle="bold"
 android:textSize="20sp"
 android:layout_marginTop="300dp"
 android:layout_marginLeft="180dp"
 />
 <!-- add clear button for clear the selected item-->
 <Button
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:text="Clear"
 android:id="@+id/clear"
 android:textSize="20sp"
 android:textStyle="bold"
 android:layout_marginTop="300dp"
 android:layout_marginLeft="20dp"
 />
</RelativeLayout>
MainACtivity.java
package com.example.radiobutton;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
 // Define the object for Radio Group,
 // Submit and Clear buttons
 private RadioGroup radioGroup;
 Button submit, clear;
 @Override
 protected void onCreate(Bundle savedInstanceState)
 {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 // Bind the components to their respective objects
 // by assigning their IDs
 // with the help of findViewById() method
submit = (Button)findViewById(R.id.submit);
 clear = (Button)findViewById(R.id.clear);
 radioGroup = (RadioGroup)findViewById(R.id.groupradio);
 // Uncheck or reset the radio buttons initially
 radioGroup.clearCheck();
 // Add the Listener to the RadioGroup
 radioGroup.setOnCheckedChangeListener(
 new RadioGroup
 .OnCheckedChangeListener() {
 @Override
 // The flow will come here when
// any of the radio buttons in the radioGroup
// has been clicked
 // Check which radio button has been clicked
public void onCheckedChanged(RadioGroup group,
 int checkedId)
 {
 // Get the selected Radio Button
 RadioButton
 radioButton
= (RadioButton)group
.findViewById(checkedId);
 }
 });
 // Add the Listener to the Submit Button
 submit.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v)
 {
 // When submit button is clicked,
 // Ge the Radio Button which is set
 // If no Radio Button is set, -1 will be returned
 int selectedId = radioGroup.getCheckedRadioButtonId();
 if (selectedId == -1) {
 Toast.makeText(MainActivity.this,
 "No answer has been selected",
Toast.LENGTH_SHORT)
 .show();
 }
 else {
 RadioButton radioButton
 = (RadioButton)radioGroup
 .findViewById(selectedId);
 // Now display the value of selected item
// by the Toast message
 Toast.makeText(MainActivity.this,
 radioButton.getText(),
Toast.LENGTH_SHORT)
 .show();
 }
Intent i=new Intent(MainActivity.this,yearwiseActivity.class);
 startActivity(i);
 }
 });
 // Add the Listener to the Submit Button
 clear.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v)
 {
 // Clear RadioGroup
 // i.e. reset all the Radio Buttons
 radioGroup.clearCheck();
 }
 });
 }
}
activity_yearwise.xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:background="#ffffff"
 android:orientation="vertical"
 tools:context=".MainActivity">
 <TextView
 android:id="@+id/textView"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:layout_marginEnd="8dp"
 android:layout_marginStart="8dp"
 android:layout_marginTop="48dp"
 android:text="Choose your Certification course"
 android:textSize="24sp"
 app:layout_constraintEnd_toEndOf="parent"
 app:layout_constraintStart_toStartOf="parent"
 app:layout_constraintTop_toTopOf="parent" />
 <CheckBox
 android:id="@+id/checkBox"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:text="python"
 android:layout_marginTop="16dp"
 android:textSize="18sp" />
 <CheckBox
 android:id="@+id/checkBox2"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
android:text="AWS Services"
 android:layout_marginTop="16dp"
 android:textSize="18sp" />
 <CheckBox
 android:id="@+id/checkBox3"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:layout_marginTop="16dp"
 android:text="Fullstack Development"
 android:textSize="18sp"
 app:layout_constraintTop_toTopOf="@+id/textView"
 tools:layout_editor_absoluteX="382dp" />
 <CheckBox
 android:id="@+id/checkBox4"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:text="Mobile application develpment"
 android:layout_marginTop="16dp"
 android:textSize="18sp"
 app:layout_constraintTop_toBottomOf="@+id/checkBox"
 tools:layout_editor_absoluteX="386dp" />
 <Button
 android:id="@+id/button"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:layout_marginTop="16dp"
 android:onClick="Check"
 android:text="submit" />
</LinearLayout>
yearwiseActivity.java
package com.example.radiobutton;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.Toast;
public class yearwiseActivity extends AppCompatActivity {
 CheckBox ch, ch1, ch2, ch3;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_yearwise);
 // Finding CheckBox by its unique ID
 ch=(CheckBox)findViewById(R.id.checkBox);
 ch1=(CheckBox)findViewById(R.id.checkBox2);
 ch2=(CheckBox)findViewById(R.id.checkBox3);
 ch3=(CheckBox)findViewById(R.id.checkBox4);
 ch.setOnCheckedChangeListener(new 
CompoundButton.OnCheckedChangeListener() {
 @Override
public void onCheckedChanged(CompoundButton compoundButton, 
boolean b) {
 ch1.setChecked(false);
 ch2.setChecked(false);
 ch3.setChecked(false);
 }
 });
 ch1.setOnCheckedChangeListener(new 
CompoundButton.OnCheckedChangeListener() {
 @Override
 public void onCheckedChanged(CompoundButton compoundButton, 
boolean b) {
 ch.setChecked(false);
 ch2.setChecked(false);
 ch3.setChecked(false);
 }
 });
 ch2.setOnCheckedChangeListener(new 
CompoundButton.OnCheckedChangeListener() {
 @Override
 public void onCheckedChanged(CompoundButton compoundButton, 
boolean b) {
 ch.setChecked(false);
 ch1.setChecked(false);
 ch3.setChecked(false);
 }
 });
 ch3.setOnCheckedChangeListener(new 
CompoundButton.OnCheckedChangeListener() {
 @Override
 public void onCheckedChanged(CompoundButton compoundButton, 
boolean b) {
 ch.setChecked(false);
 ch1.setChecked(false);
 ch2.setChecked(false);
 }
 });
 }
 // This function is invoked when the button is pressed.
 public void Check(View v)
 {
 String msg="";
 // Concatenation of the checked options in if
 // isChecked() is used to check whether
 // the CheckBox is in true state or not.
 if(ch.isChecked()) {
 msg = msg + ch.getText();
 Toast.makeText(this, msg +" " + "is Selected", 
Toast.LENGTH_SHORT).show();
 }
 else if (ch1.isChecked()) {
 msg = msg + ch1.getText();
 Toast.makeText(this, msg +" " + "is Selected",
 Toast.LENGTH_SHORT).show();
 } else if (ch2.isChecked()) {
 msg = msg + ch2.getText();
 Toast.makeText(this, msg +" " + "is Selected", 
Toast.LENGTH_SHORT).show();
 } else if (ch3.isChecked()) {
 msg = msg + ch3.getText();
 Toast.makeText(this, msg +" " + "is Selected", 
Toast.LENGTH_SHORT).show();
 }
 else
 // Toast is created to display the
 // message using show() method.
 Toast.makeText(this, msg +" " + " Nothing is selected, kindly 
select one from above checkbox",
 Toast.LENGTH_LONG).show();
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
  
                
6>: Program-6: Create a SIGNUp activity with Username and Password. Validation of password should 
happen based on the following rules: 
• Password should contain uppercase and lowercase letters. 
• Password should contain letters and numbers. 
• Password should contain special characters. 
• Minimum length of the password (the default value is 8).
On successful SIGN UP proceed to the next Login activity. Here the user should SIGN IN using the 
Username and Password created during signup activity. If the Username and Password are 
matched then navigate to the next activity which displays a message saying “Successful Login” or 
else display a toast message saying “Login Failed”. The user is given only two attempts and after 
that display a toast message saying “Failed Login Attempts” and disable the SIGN IN button. Use 
Bundle to transfer information from one activity to another.
XML code:
Activity main.xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <TextView
 android:layout_width="129dp"
 android:layout_height="45dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="168dp"
 android:layout_marginRight="168dp"
 android:layout_marginBottom="596dp"
 android:text="Sign Up"
 android:textSize="24sp"
 android:textStyle="bold"
 app:layout_constraintBottom_toBottomOf="parent"
 app:layout_constraintLeft_toLeftOf="parent"
 app:layout_constraintRight_toRightOf="parent"
 app:layout_constraintTop_toTopOf="parent" />
 <EditText
 android:id="@+id/SignUp_email"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="114dp"
 android:layout_marginRight="114dp"
 android:layout_marginBottom="464dp"
 android:ems="10"
android:hint="EmailId"
 android:inputType="textPersonName" />
 <Button
 android:id="@+id/signUpBtn"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="168dp"
 android:layout_marginRight="168dp"
 android:layout_marginBottom="245dp"
 android:text="Sign Up" />
 <EditText
 android:id="@+id/SignUp_Password"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="101dp"
 android:layout_marginRight="101dp"
 android:layout_marginBottom="385dp"
 android:ems="10"
 android:hint="Password"
 android:inputType="textPassword" />
</RelativeLayout>
Activity login.xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".loginActivity">
 <TextView
 android:id="@+id/loginTextView"
 android:layout_width="225dp"
 android:layout_height="45dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="113dp"
 android:layout_marginRight="113dp"
 android:layout_marginBottom="544dp"
 android:text="Login"
 android:textSize="30sp"
 android:textStyle="bold"
 app:layout_constraintBottom_toBottomOf="parent"
 tools:layout_editor_absoluteX="143dp" />
 <EditText
 android:id="@+id/passEditText"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
android:layout_marginEnd="124dp"
 android:layout_marginRight="124dp"
 android:layout_marginBottom="380dp"
 android:ems="10"
 android:hint="password"
 android:inputType="textPassword" />
 <Button
 android:id="@+id/loginBtn"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="218dp"
 android:layout_marginRight="218dp"
 android:layout_marginBottom="263dp"
 android:text="Login" />
 <EditText
 android:id="@+id/EmaileditText"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="127dp"
 android:layout_marginRight="127dp"
 android:layout_marginBottom="455dp"
 android:ems="10"
 android:hint="Email ID"
 android:inputType="textPersonName" />
</RelativeLayout>
Activity.loginsuccess.xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".loginsuccessActivity">
 <TextView
 android:id="@+id/textView"
 android:layout_width="match_parent"
 android:layout_height="121dp"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="-11dp"
 android:layout_marginRight="-11dp"
 android:layout_marginBottom="322dp"
 android:text="Login Successful"
 android:textSize="36sp"
 android:textStyle="bold" />
</RelativeLayout>
Java code:
Main activity .java
package com.example.program3;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import java.util.regex.Pattern;
public class MainActivity extends AppCompatActivity {
 EditText email_Sign, password_Sign;
 Button signUp_btn;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 email_Sign=(EditText)findViewById(R.id.SignUp_email);
 password_Sign=(EditText)findViewById(R.id.SignUp_Password);
 signUp_btn =(Button)findViewById(R.id.signUpBtn);
 signUp_btn.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 String email = email_Sign.getText().toString();
 String password = password_Sign.getText().toString();
 if(!isValidPassword(password)) {
 Toast.makeText(MainActivity.this, "Password doesn't 
match\n" +
 " rules", 
Toast.LENGTH_SHORT).show();
 return;
 }
 Intent intent = new 
Intent(MainActivity.this,loginActivity.class);
 intent.putExtra("email",email);
 intent.putExtra("password",password);
 startActivity(intent);
 }
 });
 }
 Pattern lowerCase= Pattern.compile("^.*[a-z].*$");
 Pattern upperCase=Pattern.compile("^.*[A-Z].*$");
 Pattern number = Pattern.compile("^.*[0-9].*$");
 Pattern special_Chara = Pattern.compile("^.*[^a-zA-Z0-9].*$");
 private Boolean isValidPassword(String password){
 if(password.length()<8) {
 return false;
 }
 if(!lowerCase.matcher(password).matches()) {
 return false;
 }
 if(!upperCase.matcher(password).matches()) {
 return false;
 }
 if(!number.matcher(password).matches()) {
return false;
 }
 if(!special_Chara.matcher(password).matches()) {
 return false;
 }
 return true;
 }
}
loginactivity.java
package com.example.program3;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
public class loginActivity extends AppCompatActivity {
 EditText emailEditText,passwordEditText;
 Button login_btn;
 int counter=2;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_login);
 emailEditText=(EditText)findViewById(R.id.EmaileditText);
 passwordEditText=(EditText)findViewById(R.id.passEditText);
 login_btn=(Button)findViewById(R.id.loginBtn);
 String registeredEmail = getIntent().getStringExtra("email");
 String registeredPassword= getIntent().getStringExtra("password");
 login_btn.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 String email = emailEditText.getText().toString();
 String password = passwordEditText.getText().toString();
 if(registeredEmail.equals(email) && 
registeredPassword.equals(password))
 {
 Intent intent= new 
Intent(loginActivity.this,loginsuccessActivity.class);
 startActivity(intent);
 }
 else {
 Toast.makeText(loginActivity.this,"Invalid 
Credentials",Toast.LENGTH_SHORT).show();
 }
 counter--;
 if(counter==0){
 Toast.makeText(getBaseContext(),"failed to login 
attempts",Toast.LENGTH_SHORT).show();
 login_btn.setEnabled(false);
 }
 }
 });
}
}
Loginsuccessactivity.java
package com.example.program3;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
public class loginsuccessActivity extends AppCompatActivity {
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_loginsuccess);
 }
}

                
7>: Program-7: Develop an application to set an image as wallpaper. On click of a button, the 
wallpaper image should start to change randomly every 30 seconds.
XML file:
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:app="http://schemas.android.com/apk/res-auto"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">
 <Button
 android:id="@+id/button1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentEnd="true"
 android:layout_alignParentRight="true"
 android:layout_alignParentBottom="true"
 android:layout_marginEnd="167dp"
 android:layout_marginRight="167dp"
 android:layout_marginBottom="409dp"
 android:text="CLICK HERE" />
</RelativeLayout>
Java file:
package com.example.program4;
import androidx.appcompat.app.AppCompatActivity;
import android.app.WallpaperManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;
public class MainActivity extends AppCompatActivity {
 Button wallpaperChange;
 Timer mytimer;
 Drawable drawable;
 WallpaperManager wpm;
 int prev=1;
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 mytimer=new Timer();
 wpm = WallpaperManager.getInstance(this);
 wallpaperChange=(Button)findViewById(R.id.button1);
 wallpaperChange.setOnClickListener(new View.OnClickListener() {
@Override public void onClick(View view) {
 setwallpaper();
 }
 });
 }
 private void setwallpaper() {
 Toast.makeText(this,"setting Wallpaper please 
wait.",Toast.LENGTH_LONG).show();
 mytimer.schedule(new TimerTask() {
 @Override
 public void run()
 {
 if(prev==1) {
 drawable = getResources().getDrawable(R.drawable.i1); 
prev = 2;
 }
 else if(prev==2) {
 drawable = getResources().getDrawable(R.drawable.i2); 
prev=3;
 }
 else if(prev==3) {
 drawable = getResources().getDrawable(R.drawable.i3); 
prev=4;
 }
 else if(prev==4) {
 drawable = getResources().getDrawable(R.drawable.i4); 
prev=5;
 }
 else if(prev==5) {
 drawable = getResources().getDrawable(R.drawable.i5); 
prev=1;
 }
 Bitmap wallpaper = ((BitmapDrawable)drawable).getBitmap(); 
try {
 wpm.setBitmap(wallpaper);
 }
 catch (IOException e)
 { e.printStackTrace();
 }
 }
 },0,30000);
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



