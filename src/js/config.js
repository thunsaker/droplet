module.exports = [
	{
		"type": "heading",
		"defaultValue": "App Configuration"
	},{
		"type": "text",
		"defaultValue": "Here is some introductory text."
	},{
		"type":"section",
		"items": [{
			"type":"heading",
			"defaultValue":"Setup"
		},{
			"type":"input",
			"messageKey":"Server",
			"label":"Server",
			"attributes": {
				"placeholder":"192.168.1.100"
			}
		},{
			"type":"input",
			"messageKey":"Password",
			"label":"Password",
			"attributes": {
				"placeholder":"secrets"
			}
		}]
	},{
		"type":"submit",
		"defaultValue": "Save Settings"
	}
];
