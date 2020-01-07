package pro.ghosh.sudipto.noobPiano;

import android.content.Intent;
import android.media.AudioAttributes;
import android.media.SoundPool;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    final static String TAG = "noobPianoDebug";

    private SoundPool soundPool = null;

    private int lowASoundId;
    private int cSoundId;
    private int dSoundId;
    private int eSoundId;
    private int fSoundId;
    private int gSoundId;
    private int aSoundId;
    private int bSoundId;
    private int highCSoundId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        soundPool = new SoundPool.Builder()
                .setMaxStreams(9)
                .setAudioAttributes(
                        new AudioAttributes.Builder()
                                .setUsage(AudioAttributes.USAGE_MEDIA)
                                .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                                .build()
                )
                .build();

        lowASoundId = soundPool.load(this, R.raw.a_low, 1);
        cSoundId = soundPool.load(this, R.raw.c, 1);
        dSoundId = soundPool.load(this, R.raw.d, 1);
        eSoundId = soundPool.load(this, R.raw.e, 1);
        fSoundId = soundPool.load(this, R.raw.f, 1);
        gSoundId = soundPool.load(this, R.raw.g, 1);
        aSoundId = soundPool.load(this, R.raw.a, 1);
        bSoundId = soundPool.load(this, R.raw.b, 1);
        highCSoundId = soundPool.load(this, R.raw.c_high, 1);

        Log.d(TAG, "onCreate: sounds loaded");
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu, menu);
        Log.d(TAG, "onCreateOptionsMenu: menu drawn");
        return super.onCreateOptionsMenu(menu);
    }

    public void playLowA(View view) {
        soundPool.play(lowASoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playLowA: low a played");
    }

    public void playC(View view) {
        soundPool.play(cSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playC: c played");
    }

    public void playD(View view) {
        soundPool.play(dSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playD: d played");
    }

    public void playE(View view) {
        soundPool.play(eSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playE: e played");
    }

    public void playF(View view) {
        soundPool.play(fSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playF: f played");
    }

    public void playG(View view) {
        soundPool.play(gSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playG: g played");
    }

    public void playA(View view) {
        soundPool.play(aSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playA: a played");
    }

    public void playB(View view) {
        soundPool.play(bSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playB: b played");
    }

    public void playHighC(View view) {
        soundPool.play(highCSoundId, 1.0f,1.0f,1,0,1.0f);
        Log.d(TAG, "playHighC: high c played");
    }

    public void launchAbout(MenuItem item) {
        startActivity(new Intent(this, AboutActivity.class));
    }
}
