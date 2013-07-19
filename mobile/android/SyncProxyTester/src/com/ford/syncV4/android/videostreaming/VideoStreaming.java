package com.ford.syncV4.android.videostreaming;

import java.io.IOException;
import java.io.InputStream;

/**
 * Created by admin on 7/19/13.
 */
public class VideoStreaming {

    public byte[] readTestVideoFileFromStream(InputStream stream) throws IOException {
        int size = stream.available();
        byte[] buffer = new byte[size];
        stream.read(buffer);
        stream.close();
        return buffer;
    }

}
