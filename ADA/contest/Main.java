import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.HashMap;
import java.util.ArrayList;

public class Main {
    public static void main(final String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Pattern pattern = Pattern.compile("^([0-9]+) ([a-zA-Z]+) (.*)$");
        Matcher matcher;
        ArrayList<String> bailes = new ArrayList<String>();
        ArrayList<String> comidas = new ArrayList<String>();
        ArrayList<String> cultura = new ArrayList<String>();
        
        try {
            final String[] maximos = br.readLine().split(" ");
            int ba = Integer.parseInt(maximos[0]);
            int co = Integer.parseInt(maximos[1]);
            int cu = Integer.parseInt(maximos[2]);

            final String[] types = {"BAILES", "COMIDA", "CULTURA"};
            int current = 0;
            HashMap<String, Integer> cgroup = new HashMap<String, Integer>();
            cgroup.put("BAILES", ba);
            cgroup.put("COMIDA", co);
            cgroup.put("CULTURA", cu);

            while(true) {
                (matcher = pattern.matcher(br.readLine())).find();
                if(!matcher.group(2).equals(types[current])) {
                    for(int i = 0; i < 3; i++) {
                        if(types[i].equals(matcher.group(2))) {
                            current = i;
                        }
                    }
                }

                if(Integer.parseInt(matcher.group(1)) <= cgroup.get(types[current])) {
                    cgroup.put(types[current], cgroup.get(types[current]) - Integer.parseInt(matcher.group(1)));

                    switch(matcher.group(2)) {
                        case "BAILES":
                            bailes.add(matcher.group(3));
                            break;
                        case "COMIDA":
                            comidas.add(matcher.group(3));
                            break;
                        case  "CULTURA":
                            cultura.add(matcher.group(3));
                            break;
                    }
                }
            }
        } catch(Exception e) {
            if(bailes.size() > 0) {
                System.out.println("BAILES");
                for(int i = 0; i < bailes.size(); i++) {
                    System.out.println(bailes.get(i));
                }
            }

            if(comidas.size() > 0) {
                System.out.println("COMIDA");
                for(int i = 0; i < comidas.size(); i++) {
                    System.out.println(comidas.get(i));
                }
            }

            if(cultura.size() > 0) {
                System.out.println("CULTURA");
                for(int i = 0; i < cultura.size(); i++) {
                    System.out.println(cultura.get(i));
                }
            }
            System.exit(0);
        }
    }
}