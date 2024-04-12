package com.project.cbnu_ai_opensw;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TabHost;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TabHost tabHost = findViewById(android.R.id.tabhost);
        tabHost.setup();

        TabHost.TabSpec tab1 = tabHost.newTabSpec("tab1");
        tab1.setContent(R.id.tab1);
        TextView tab1TextView = new TextView(this);
        tab1TextView.setText("강아지");
        tab1.setIndicator(tab1TextView);
        tabHost.addTab(tab1);

        TabHost.TabSpec tab2 = tabHost.newTabSpec("tab2");
        tab2.setContent(R.id.tab2);
        TextView tab2TextView = new TextView(this);
        tab2TextView.setText("고양이");
        tab2.setIndicator(tab2TextView);
        tabHost.addTab(tab2);

        TabHost.TabSpec tab3 = tabHost.newTabSpec("tab3");
        tab3.setContent(R.id.tab3);
        TextView tab3TextView = new TextView(this);
        tab3TextView.setText("토끼");
        tab3.setIndicator(tab3TextView);
        tabHost.addTab(tab3);

        TabHost.TabSpec tab4 = tabHost.newTabSpec("tab4");
        tab4.setContent(R.id.tab4);
        TextView tab4TextView = new TextView(this);
        tab4TextView.setText("말");
        tab4.setIndicator(tab4TextView);
        tabHost.addTab(tab4);
    }
}