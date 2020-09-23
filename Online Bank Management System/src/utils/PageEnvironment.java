package utils;


import configs.SysConfigs;

public class PageEnvironment {
	
	private String url_host;
	private String url_assets;
	private String url_apppath;
	private String url_uri;
	private String page_title;
	private String view_file;

	public PageEnvironment(){
		url_host 	= SysConfigs.url_Host;
		url_assets 	= SysConfigs.url_Assets;
		url_apppath = SysConfigs.url_AppPath;
	}

	public String getUrl_uri() {
		return url_uri;
	}

	public void setUrl_uri(String url_uri) {
		this.url_uri = url_uri;
	}

	
	public String getUrl_apppath() {
		return url_apppath;
	}

	public void setUrl_apppath(String url_app) {
		this.url_apppath = url_app;
	}
	
	public String getView_file() {
		return view_file;
	}

	public void setView_file(String view_file) {
		this.view_file = view_file;
	}

	public void setViewFile(String view_file) {
		this.view_file = view_file;
	}
	
	public String getUrl_host() {
		return url_host;
	}

	public void setUrl_host(String url_Host) {
		this.url_host = url_Host;
	}

	public String getUrl_assets() {
		return url_assets;
	}

	public void setUrl_assets(String url_Assets) {
		this.url_assets = url_Assets;
	}

	public String getPage_title() {
		return page_title;
	}

	public void setPage_title(String page_title) {
		this.page_title = page_title;
	}

	
}
