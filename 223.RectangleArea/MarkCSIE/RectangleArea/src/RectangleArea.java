
public class RectangleArea {

    public static void main(String[] args) {
        RectangleArea test = new RectangleArea();
    }
    
        public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C - A) * (D - B);
        int areaB = (G - E) * (H - F);

        // no overlap
        if (A > G || E > C || B > H || F > D) {
            return areaA + areaB;
        } else {
            int right = Math.min(C, G);
            int left = Math.max(A, E);
            int top = Math.min(H, D);
            int bottom = Math.max(F, B);
            return areaA + areaB - (right - left) * (top - bottom);
        }
    }
}
