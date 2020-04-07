import android.speech.tts.TextToSpeech;

public class ReadActivity extends AppCompatActivity implements  TextToSpeech.OnInitListener {

    private TextToSpeech tts;

    String content = "This text will be read by the Android Text to Speech.";

    int maxSpeechLength = 0;
    Boolean isUnderLimitLenght = false;
    Boolean isTtsReady = false;
    Boolean isSpeaking = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        tts = new TextToSpeech(ReadActivity.this, ReadActivity.this);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR2) {

            maxSpeechLength = tts.getMaxSpeechInputLength();

            if (content .length() > maxSpeechLength ) {
                isUnderLimitLenght = false;
            }
            else {
                isUnderLimitLenght = true;
            }
        }
        else {
          isUnderLimitLenght = true;
        }

        if(isUnderLimitLenght && isTtsReady  ){
              textToSpeech()
       }
    }

    @Override
    public void onDestroy() {
        if (tts != null) {
            tts.stop();
            tts.shutdown();
        }
        super.onDestroy();
    }

    @Override
    public void onInit(int i) {
        if (i == TextToSpeech.SUCCESS) {
            int result = tts.setLanguage(Locale.US);
            if (result == TextToSpeech.LANG_MISSING_DATA
                    || result == TextToSpeech.LANG_NOT_SUPPORTED) {
                Log.e("TTS", "This Language is not supported");
                isTtsReady = false;
            } else {
                btnTextToSpeech.setEnabled(true);
                isTtsReady = true;
            }
        } else {
             isTtsReady = false;
            Toast.makeText(this, "Your device do not support TextToSpeech....", Toast.LENGTH_SHORT).show();
        }
    }

    private void textToSpeech() {

        if(tts.isSpeaking() == false){
            String text = content_content;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                tts.speak(text, TextToSpeech.QUEUE_FLUSH, null,null);
            } else {
                HashMap<String, String> map = new HashMap<>();
                map.put(TextToSpeech.Engine.KEY_PARAM_UTTERANCE_ID, "TheCodeProgram");
                tts.speak(text, TextToSpeech.QUEUE_FLUSH, map);
            }
            isSpeaking = true;
        }
        else if(tts.isSpeaking()){
            if(tts.isSpeaking()){
                tts.stop();
            }
            isSpeaking = false;
        }
    }

}