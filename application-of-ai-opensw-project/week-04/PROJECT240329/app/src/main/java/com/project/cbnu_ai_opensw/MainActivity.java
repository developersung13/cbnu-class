package com.project.cbnu_ai_opensw;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.Toast;

import com.project.cbnu_ai_opensw.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

    private boolean tf_startCheckbox_checked = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());


        binding.startCheckbox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                tf_startCheckbox_checked = isChecked;
                if (tf_startCheckbox_checked) {
                    binding.relativeLayoutRadioGroup.setVisibility(View.VISIBLE);
                    binding.animalImageView.setVisibility(View.VISIBLE);
                } else {
                    binding.relativeLayoutRadioGroup.setVisibility(View.INVISIBLE);
                    binding.animalImageView.setVisibility(View.INVISIBLE);
                }
            }
        });

        binding.selectImageCompleteBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (tf_startCheckbox_checked) {
                    int checkedGroupIdx = binding.animalRadioGroup.getCheckedRadioButtonId();
                    switch (checkedGroupIdx) {
                        case 1:
                            binding.animalImageView.setImageResource(R.drawable.dog);
                            break;
                        case 2:
                            binding.animalImageView.setImageResource(R.drawable.cat);
                            break;
                        case 3:
                            binding.animalImageView.setImageResource(R.drawable.rabbit);
                            break;
                        default:
                            Toast.makeText(getApplicationContext(), "동물 먼저 선택하세요", Toast.LENGTH_SHORT).show();
                    }
                }
            }
        });
    }
}