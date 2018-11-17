using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Forms;
using System.Windows.Media.Imaging;
namespace ConsoleApplication1
{
    class Program
    {
        /// <summary>
        /// 生成文字图片
        /// </summary>
        /// <param name="text"></param>
        /// <param name="isBold"></param>
        /// <param name="fontSize"></param>
        public static void  CreateImage(string text, bool isBold, int fontSize)
        {
            
            

            int wid = 400;
            int high = 200;
            Font font;
            if (isBold)
            {
                font = new Font("Arial", fontSize, FontStyle.Bold);

            }
            else
            {
                font = new Font("Arial", fontSize, FontStyle.Regular);

            }
            //绘笔颜色
            SolidBrush brush = new SolidBrush(Color.Black);
            StringFormat format = new StringFormat(StringFormatFlags.NoClip);
            Bitmap image = new Bitmap(wid, high);
            Graphics g = Graphics.FromImage(image);
            SizeF sizef = g.MeasureString(text, font, PointF.Empty, format);//得到文本的宽高
            int width = (int)(sizef.Width + 1);
            int height = (int)(sizef.Height + 1);
            image.Dispose();
            image = new Bitmap(width, height);
            g = Graphics.FromImage(image);
            g.Clear(Color.White);//透明

            RectangleF rect = new RectangleF(0, 0, width, height);
            //绘制图片
            g.DrawString(text, font, brush, rect);
            //释放对象
            g.Dispose();
            string path = "C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\ConsoleApplication1\\ConsoleApplication1\\ss.bmp";
            image.Save(path);


            string BMPFiles = "C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\ConsoleApplication1\\ConsoleApplication1\\ss.bmp";

         //BMP文件所在路径

         BitmapImage BitImage = new BitmapImage (new Uri(BMPFiles, UriKind.Absolute));
         JpegBitmapEncoder encoder = new JpegBitmapEncoder ();
         encoder.Frames.Add (BitmapFrame.Create (BitImage));
         String JpegImage = "C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\ConsoleApplication1\\ConsoleApplication1\\qq.jpeg";

         //JPG文件件路径
         FileStream fileStream = new FileStream (JpegImage, FileMode.Create, FileAccess.ReadWrite);
         encoder.Save (fileStream);
         fileStream.Close ();

        }
        static void Main(string[] args)
        {
            //string[] s = {"a","b","c","d"};
            string s = "\n\n\n一等奖：AAAA\n二等奖：BBBB,CCCC\n三等奖：DDDD,EEEE,FFFF\n                GGGG,HHHH\n\n\n";
            CreateImage(s, true, 33);
           
        }

    }
}
