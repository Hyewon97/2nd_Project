package com.sportslight.mymy.controller;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sportslight.dto.FavoriteDTO;
import com.sportslight.dto.HeartDTO;
import com.sportslight.dto.MemberFavorDTO;
import com.sportslight.dto.NoticeDTO;
import com.sportslight.mymy.service.MymyService;

import lombok.NoArgsConstructor;

@CrossOrigin(origins = {"http://localhost:3000"})
@RestController
@NoArgsConstructor
public class MymyController {

	@Autowired
	private MymyService myService;
	
	// 내 선호 팀 / 리그 정보 출력
	@PostMapping("/myteam")
	public Map<String, Object> getFavorExecute(int memberNum) {
		System.out.println("내 선호팀 출력");
		return myService.getFavorService(memberNum);
		
	}
	
	// 내 팀 / 리그 수정
	@PostMapping("/myteam/update")
	public String updateFavorExcute(MemberFavorDTO mfdto) {
		System.out.println("내 선호팀 수정");
		return myService.updateFavorTeamService(mfdto);
	}
	
//	// 내 팀 / 리그 수정
//	@PostMapping("/myteam/update")
//	public void updateFavorExcute(MemberFavorDTO mfdto) {
//		System.out.println("내 선호팀 수정");
//		myService.updateFavorTeamService(mfdto);
//	}

	
	// 좋아요 동영상 가져오기
	@PostMapping("/myvideo/heart")
	public List<HeartDTO> getHeartExecute(int memberNum){
		System.out.println("좋아요 동영상 출력");
		return myService.getHeartVideoService(memberNum);	
	}
	
	// 즐겨찾기 동영상 가져오기
	@PostMapping("/myvideo/favorite")
	public List<FavoriteDTO> getFavoriteExecute(int memberNum){
		System.out.println("즐겨찾기 동영상 출력");
		System.out.println(myService.getFavoriteVideoService(memberNum).get(0).getVideoNum());
		return myService.getFavoriteVideoService(memberNum);
	}
	
	// 공지사항 리스트 가져오기
	@GetMapping("/notice")
	public List<NoticeDTO> getNoticeListExecute(){
		System.out.println("공지사항 리스트 출력");
		return myService.getNoticeListService();
	}
	
	// 공지사항 세부 보기
	@GetMapping("/notice/{noticeNum}")
	public NoticeDTO getNoticeViewExecute(@PathVariable("noticeNum") int noticeNum) {
		System.out.println("공지사항 내용 출력");
		return myService.getNoticeViewService(noticeNum);
	}
	
}
