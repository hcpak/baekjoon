import java.util.*;
public class Main {
    static int N, answer =0;
    static List<point> list;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        list = new ArrayList<>();
        int start, end;
        for(int i=0; i < N; i++){
            start = sc.nextInt();
            end = sc.nextInt();
            list.add(new point(start,end));
        }
        list.sort(new Comparator<point>(){
            @Override
            public int compare(point arg0, point arg1){
                if(arg0.end == arg1.end){
                    if(arg0.start > arg1.start){
                        return 1;
                    }else if(arg0.start < arg1.start){
                        return -1;
                    }
                    return 0;
                }else {
                    if(arg0.end > arg1.end){
                        return 1;
                    }else if(arg0.end < arg1.end){
                        return -1;
                    }
                    return 0;
                }
            }
        });
        int end_time =0, answer =0;
        for(int i =0; i < N; i++){
            if(end_time <= list.get(i).start){
                end_time = list.get(i).end;
                answer++;
            }
        }
        System.out.println(answer);
    }
    
    static class point{
        int start, end;
        point(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
}
