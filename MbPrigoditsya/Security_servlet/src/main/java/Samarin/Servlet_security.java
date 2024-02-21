package Samarin;

import java.io.IOException;
import java.util.Arrays;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Servlet_security
 */
public class Servlet_security extends HttpServlet {
	private static final long serialVersionUID = 1L;
	String Kitchen []= {"Ivanov", "Smirnov", "Sidorov"};
	String MH []= {"ysachev", "kshishtovski", "bulkin"};
	String Ofice []= {"paigildin", "stolyarov", "samoilov"};
	String state = "";
    /**
     * Default constructor. 
     */
    public Servlet_security() {
    	
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("<body>\r\n"
				+ "		<h1>Security by Dima Samarin 4134k</h1>\r\n"
				+ "		<form action=\"Servlet_security\" method= \"post\">\r\n"
				+ "			   <input type=\"submit\" name=\"data\" value=\"Kitchen\" >\r\n"
				+ "			   <input type=\"submit\" name=\"data\" value=\"Meeting Hall\" >\r\n"
				+ "			<input type=\"submit\" name=\"data\" value=\"Ofice\" >\r\n"
				+ "			</form>\r\n"
				+ "	</body>");
		
		
		
	}
	protected void RemoveAccess(HttpServletRequest request, String data, String state) {
		
		int position = Integer.valueOf(data.substring(data.length() - 1));
		System.out.println(position);
		switch (state) {
		case ("Kitchen"):
			Kitchen[position]="";
			break;
		case ("Meeting Hall"):
			MH[position]="";
			break;
		case ("Ofice"):
			Ofice[position]="";
			break;
		default:
			break;
		}
	}
	protected void AddAccess(HttpServletRequest request, String data) {
		String name = request.getParameter("name").trim();
		System.out.println(data);
		switch (data) {
		case ("Add Kitchen"):
			Kitchen = Arrays.copyOf(Kitchen, Kitchen.length+1);
			Kitchen[Kitchen.length-1] = name;
			break;
			
		case ("Add Meeting Hall"):
			MH = Arrays.copyOf(MH, MH.length+1);
			MH[MH.length-1] = name;
			break;
			
		case ("Add Ofice"):
			Ofice = Arrays.copyOf(Ofice, Ofice.length+1);
			Ofice[Ofice.length-1] = name;
			break;
		default:
			break;
		}
		
		
		
	}
	
	protected void RenderAddAccess(HttpServletResponse response, String data) throws ServletException, IOException {
		response.getWriter().append("<form action=\"\" method=\"post\">\r\n"
				+ "    Enter Name: <input type=\"text\" name=\"name\" size=\"20\">\r\n"
				+ "    <input type=\"submit\" name= \"Add\" value=\"Add "+data+ "\" />");
		
	}
	
	protected void makeTable(HttpServletResponse response, String toRender[]) throws ServletException, IOException {
		String outprint = "";
		for (int i = 0; i<toRender.length; i++) {
			 
			 if (toRender[i]!="") {
				 outprint +="<h2>"+toRender[i]+" <input type=\"submit\" name= \"Remove\" value=\"Remove "+String.valueOf(i)+"\"/></h2>";
				 System.out.println(outprint);
			 }
			 
		}
		response.getWriter().append(outprint);
		
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		doGet(request, response);
		
		
		
		String Remove= request.getParameter("Remove");
		if (Remove!=null) {
			RemoveAccess(request, Remove, state);
		}
		String Add = request.getParameter("Add");
		if (Add!=null) {
			AddAccess(request, Add);
		}
		
		String data = request.getParameter("data");
		state = data;
		RenderAddAccess(response, data);
		
		if (data==null) return;
		switch (data) {
		case ("Kitchen"): 
			
			makeTable(response, Kitchen);
			break;
		case ("Meeting Hall"):
			makeTable(response, MH);
			break;
		case ("Ofice"):
			makeTable(response, Ofice);
			break;
		default: 
			break;
		
	}
		
		}

}
