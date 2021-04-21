package zstegosaurus;
import java.awt.image.BufferedImage;
import java.awt.image.Raster;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;
import java.util.Hashtable;
import javax.imageio.ImageIO;

public class addflag{
    
    public static int[] strToBits(String flag){
        int[] bits =new int[flag.length()*8];
        for(int x=0;x<flag.length();x++){
            char c=flag.charAt(x);
            int ascii = (int)c;
            int bit;
            for(int i=0;i<8;i++){
                if ( (ascii & 0x80) > 0 ){
                    bit = 1;
                } else {
                    bit = 0;
                }
                bits[x*8+i]=bit;
                //System.out.printf("Bit=%d\n", bit);
                ascii=ascii<<1;
            }
            //System.out.printf("\n");
        }
        return bits;
    }

    


    public static void main(String[] args) {
        int[] bits=strToBits("h15_n@m3_i5nt_g3rard");
        System.out.printf("Bits length: %d\n",bits.length);
        int c=0;
        for(int j=0; j < bits.length; j++){
            c = c<<1 | bits[j];
            System.out.printf("%d%s %s", bits[j], (j%8 == 7 ? "\n": ""), (j%8 == 8 ? (char)c : ""));
            if (j%8 == 7){ c = 0;}
        }
        //read image file
        
        try {
            BufferedImage image = ImageIO.read(new File("./gerald.png"));
            System.out.printf("Read file in\n");
            //convert to raster
            Raster srcRaster = image.getData();
            if (srcRaster != null){
                System.out.printf("Got Raster\n");
            }
            WritableRaster destRaster = srcRaster.createCompatibleWritableRaster();
            if (destRaster != null){System.out.printf("Got writable raster\n");}
            image.copyData(destRaster);

            //alter image
            // get pixel 00 band 0 and output
            int[] pixel = new int[4];
            pixel = destRaster.getPixel(0, 0,  pixel);
            System.out.printf("pixel (0,0) band 0 = %s,%s,%s\n", Integer.toHexString(pixel[0]),Integer.toHexString(pixel[1]),Integer.toHexString(pixel[2]));
            
            for(int i=0;i<bits.length;i++){
                pixel=destRaster.getPixel(i,0,pixel);
                if(bits[i]==0){
                    //force lsb to 0
                    pixel[0]&=0xfe;
                    pixel[1]&=0xfe;
                    pixel[2]&=0xfe;

                }
                else{
                    //force lsb to 1
                    pixel[0]|=0x01;
                    pixel[1]|=0x01;
                    pixel[2]|=0x01;
                }
                destRaster.setPixel(i,0,pixel);

            }
            //pixel[0]=128; pixel[1]=128; pixel[3]=128;
            //for (int i=0; i < 100; i++){
              //  destRaster.setPixel(i, i, pixel);
            //}

            //save as file
            BufferedImage finalImage = new BufferedImage(image.getColorModel(),destRaster,image.isAlphaPremultiplied(),new Hashtable<>());
            System.out.printf("Final Image Width: %d\n",finalImage.getWidth());
            File outfile = new File("./zgerald.png");
            if (outfile != null){ System.out.printf("Created outfile, isWritable:%s\n", outfile.canWrite()?"y":"n");}
            ImageIO.write(finalImage,"PNG",outfile);







        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        

    }
    
}
