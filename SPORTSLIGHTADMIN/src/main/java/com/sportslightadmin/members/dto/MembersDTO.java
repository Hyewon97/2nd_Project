package com.sportslightadmin.members.dto;

import java.sql.Date;

import org.springframework.stereotype.Component;



@Component
public class MembersDTO {
	private String memberEmailt; // 사용자 이메일
	private String memberPasst; // 사용자 비밀번호
	private String memberProfilet; // 사용자 프로필 이름
	private Date memberRegt; // 사용자 가입 일자
	private char memberLockedt; // 사용자 잠금 여부
	private char memberLeavet; // 사용자 탈퇴 여부
	

	public MembersDTO() {
		
	}


	public String getMemberEmailt() {
		return memberEmailt;
	}


	public void setMemberEmailt(String memberEmailt) {
		this.memberEmailt = memberEmailt;
	}


	public String getMemberPasst() {
		return memberPasst;
	}


	public void setMemberPasst(String memberPasst) {
		this.memberPasst = memberPasst;
	}


	public String getMemberProfilet() {
		return memberProfilet;
	}


	public void setMemberProfilet(String memberProfilet) {
		this.memberProfilet = memberProfilet;
	}


	public Date getMemberRegt() {
		return memberRegt;
	}


	public void setMemberRegt(Date memberRegt) {
		this.memberRegt = memberRegt;
	}


	public char getMemberLockedt() {
		return memberLockedt;
	}


	public void setMemberLockedt(char memberLockedt) {
		this.memberLockedt = memberLockedt;
	}


	public char getMemberLeavet() {
		return memberLeavet;
	}


	public void setMemberLeavet(char memberLeavet) {
		this.memberLeavet = memberLeavet;
	}


	
	
}









